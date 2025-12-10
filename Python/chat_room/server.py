import socket
import threading

# 配置项
HOST = '0.0.0.0'    # 监听所有可用接口 (允许局域网连接)
PORT = 12345        # 服务器端口
BUFFER_SIZE = 1024  # 缓冲区大小
ENCODING = 'utf-8'  # 编码格式

# 存储已连接的客户端 (socket -> nickname)
clients = {}

def get_host_ip():
    """
    获取本机局域网IP，用于提示用户
    """
    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        s.connect(('8.8.8.8', 80))
        ip = s.getsockname()[0]
    except Exception:
        ip = '127.0.0.1'
    finally:
        s.close()
    return ip

def broadcast(message, sender_socket=None):
    """
    将消息广播给所有其他客户端
    :param message: 要发送的消息 (bytes)
    :param sender_socket: 发送者的socket对象，如果是系统消息则为None
    """
    for client_socket in list(clients.keys()):
        if client_socket != sender_socket:
            try:
                client_socket.send(message)
            except Exception as e:
                print(f"[错误] 发送消息失败: {e}")
                remove_client(client_socket)

def remove_client(client_socket):
    """
    移除客户端并通知其他人
    """
    if client_socket in clients:
        nickname = clients[client_socket]
        del clients[client_socket]
        client_socket.close()
        print(f"[断开] {nickname} 已断开连接")
        broadcast(f"[系统] {nickname} 离开了聊天室".encode(ENCODING))

def handle_client(client_socket, client_address):
    """
    处理单个客户端的连接
    """
    print(f"[连接] 新连接来自 {client_address}")
    
    try:
        # 1. 接收昵称
        client_socket.send("请输入您的昵称: ".encode(ENCODING))
        nickname = client_socket.recv(BUFFER_SIZE).decode(ENCODING).strip()
        
        if not nickname:
            nickname = f"用户{client_address[1]}" # 默认昵称
            
        clients[client_socket] = nickname
        print(f"[登录] {nickname} ({client_address}) 加入了聊天室")
        broadcast(f"[系统] {nickname} 加入了聊天室".encode(ENCODING), client_socket)
        
        # 2. 消息循环
        while True:
            message = client_socket.recv(BUFFER_SIZE)
            if not message:
                break # 连接关闭
            
            msg_decoded = message.decode(ENCODING)
            print(f"[{nickname}] {msg_decoded}")
            
            # 广播消息
            broadcast(f"{nickname}: {msg_decoded}".encode(ENCODING), client_socket)
            
    except ConnectionResetError:
        print(f"[异常] 客户端 {client_address} 强制断开连接")
    except Exception as e:
        print(f"[错误] 处理客户端 {client_address} 时发生错误: {e}")
    finally:
        remove_client(client_socket)

def start_server():
    """
    启动服务器
    """
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # 允许端口复用，避免重启时由 "Address already in use" 错误
    server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    
    try:
        server.bind((HOST, PORT))
        server.listen()
        
        host_ip = get_host_ip()
        print(f"[启动] 服务器正在运行")
        print(f"[信息] 本机局域网IP: {host_ip}")
        print(f"[信息] 监听端口: {PORT}")
        print("[等待] 等待客户端连接...")
        
        while True:
            client_socket, client_address = server.accept()
            # 为每个客户端启动一个新线程
            thread = threading.Thread(target=handle_client, args=(client_socket, client_address))
            thread.daemon = True # 设置为守护线程，主线程退出时子线程自动退出
            thread.start()
            print(f"[状态] 当前在线人数: {threading.active_count() - 1}")
            
    except Exception as e:
        print(f"[致命错误] 服务器发生错误: {e}")
    finally:
        server.close()

if __name__ == "__main__":
    start_server()
