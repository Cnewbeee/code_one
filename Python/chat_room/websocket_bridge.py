import socket
import threading
import base64
import hashlib
import struct
import sys

# 配置
WS_HOST = '0.0.0.0'
WS_PORT = 12346       # WebSocket 监听端口
TCP_SERVER_IP = '127.0.0.1' # 后端 TCP 聊天服务器 IP
TCP_SERVER_PORT = 12345     # 后端 TCP 聊天服务器端口

BUFFER_SIZE = 4096

def get_host_ip():
    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        s.connect(('8.8.8.8', 80))
        ip = s.getsockname()[0]
    except Exception:
        ip = '127.0.0.1'
    finally:
        s.close()
    return ip

def handshake(client_socket):
    """
    处理 WebSocket 握手
    """
    try:
        request = client_socket.recv(1024).decode('utf-8')
        headers = {}
        for line in request.split('\r\n'):
            if ': ' in line:
                key, value = line.split(': ', 1)
                headers[key] = value
        
        if 'Sec-WebSocket-Key' not in headers:
            return False
        
        sec_websocket_key = headers['Sec-WebSocket-Key']
        magic_string = '258EAFA5-E914-47DA-95CA-C5AB0DC85B11'
        accept_key = base64.b64encode(hashlib.sha1((sec_websocket_key + magic_string).encode('utf-8')).digest()).decode('utf-8')
        
        response = (
            "HTTP/1.1 101 Switching Protocols\r\n"
            "Upgrade: websocket\r\n"
            "Connection: Upgrade\r\n"
            f"Sec-WebSocket-Accept: {accept_key}\r\n\r\n"
        )
        client_socket.send(response.encode('utf-8'))
        return True
    except Exception as e:
        print(f"[Bridge] 握手失败: {e}")
        return False

def decode_frame(data):
    """
    解码 WebSocket 帧
    """
    if len(data) < 2:
        return None, None
    
    byte1 = data[0]
    byte2 = data[1]
    
    fin = byte1 & 0x80
    opcode = byte1 & 0x0F
    masked = byte2 & 0x80
    payload_len = byte2 & 0x7F
    
    if opcode == 8: # Close frame
        return 'close', None
    
    head_len = 2
    if payload_len == 126:
        payload_len = struct.unpack(">H", data[2:4])[0]
        head_len = 4
    elif payload_len == 127:
        payload_len = struct.unpack(">Q", data[2:10])[0]
        head_len = 10
        
    if masked:
        masking_key = data[head_len:head_len+4]
        head_len += 4
        payload_data = data[head_len:head_len+payload_len]
        decoded = bytearray()
        for i in range(len(payload_data)):
            decoded.append(payload_data[i] ^ masking_key[i % 4])
        return 'text', decoded.decode('utf-8')
    else:
        return 'text', data[head_len:head_len+payload_len].decode('utf-8')

def encode_frame(message):
    """
    编码 WebSocket 帧 (发送给客户端，不需要掩码)
    """
    data = message.encode('utf-8')
    length = len(data)
    
    frame = bytearray()
    frame.append(0x81) # FIN + Text Opcode
    
    if length <= 125:
        frame.append(length)
    elif length <= 65535:
        frame.append(126)
        frame.extend(struct.pack(">H", length))
    else:
        frame.append(127)
        frame.extend(struct.pack(">Q", length))
        
    frame.extend(data)
    return frame

def forward_ws_to_tcp(ws_socket, tcp_socket):
    """
    从 WebSocket 读取数据 -> 解码 -> 发送给 TCP Server
    """
    try:
        while True:
            data = ws_socket.recv(BUFFER_SIZE)
            if not data:
                break
            
            opcode, message = decode_frame(data)
            if opcode == 'close':
                break
            if message:
                print(f"[Bridge] WS -> TCP: {message}")
                tcp_socket.send(message.encode('utf-8'))
    except Exception as e:
        print(f"[Bridge] WS -> TCP 错误: {e}")
    finally:
        tcp_socket.close()
        ws_socket.close()

def forward_tcp_to_ws(tcp_socket, ws_socket):
    """
    从 TCP Server 读取数据 -> 编码 -> 发送给 WebSocket
    """
    try:
        while True:
            data = tcp_socket.recv(BUFFER_SIZE)
            if not data:
                break
            
            message = data.decode('utf-8')
            print(f"[Bridge] TCP -> WS: {message}")
            frame = encode_frame(message)
            ws_socket.send(frame)
    except Exception as e:
        print(f"[Bridge] TCP -> WS 错误: {e}")
    finally:
        ws_socket.close()
        tcp_socket.close()

def handle_client(ws_socket, addr):
    print(f"[Bridge] 新 Web 连接: {addr}")
    
    if not handshake(ws_socket):
        print(f"[Bridge] {addr} 握手失败")
        ws_socket.close()
        return

    # 连接到后端 TCP 服务器
    try:
        tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        tcp_socket.connect((TCP_SERVER_IP, TCP_SERVER_PORT))
    except Exception as e:
        print(f"[Bridge] 无法连接到后端 TCP 服务器: {e}")
        ws_socket.close()
        return

    # 启动双向转发线程
    t1 = threading.Thread(target=forward_ws_to_tcp, args=(ws_socket, tcp_socket))
    t2 = threading.Thread(target=forward_tcp_to_ws, args=(tcp_socket, ws_socket))
    t1.daemon = True
    t2.daemon = True
    t1.start()
    t2.start()

def start_bridge():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server.bind((WS_HOST, WS_PORT))
    server.listen(5)
    
    host_ip = get_host_ip()
    print(f"==========================================")
    print(f" WebSocket 网桥已启动")
    print(f" 监听地址: {WS_HOST}:{WS_PORT}")
    print(f" 本机局域网IP: {host_ip}")
    print(f" 后端 TCP 服务器: {TCP_SERVER_IP}:{TCP_SERVER_PORT}")
    print(f" 请在浏览器中打开 web_client.html 并连接到 ws://{host_ip}:{WS_PORT}")
    print(f"==========================================")
    
    try:
        while True:
            client, addr = server.accept()
            t = threading.Thread(target=handle_client, args=(client, addr))
            t.daemon = True
            t.start()
    except KeyboardInterrupt:
        print("\n[Bridge] 停止运行")
    finally:
        server.close()

if __name__ == "__main__":
    start_bridge()
