import socket
import threading
import sys

# 配置项
DEFAULT_HOST = '127.0.0.1'  # 默认服务器IP地址
PORT = 12345                # 服务器端口
BUFFER_SIZE = 1024          # 缓冲区大小
ENCODING = 'utf-8'          # 编码格式

def receive_messages(client_socket):
    """
    接收服务器消息的线程函数
    """
    while True:
        try:
            message = client_socket.recv(BUFFER_SIZE).decode(ENCODING)
            if not message:
                print("\n[系统] 与服务器的连接已断开。")
                client_socket.close()
                sys.exit()
            
            # 打印接收到的消息
            # 使用 \r 清除当前行（如果用户正在输入），打印消息后再恢复提示符
            # 注意：简单的控制台聊天室很难完美处理输入时的输出干扰，这里做简单处理
            print(f"\r{message}\n> ", end="")
            
        except OSError:
            break # socket已关闭
        except Exception as e:
            print(f"\n[错误] 接收消息出错: {e}")
            client_socket.close()
            break

def start_client():
    """
    启动客户端
    """
    # 获取服务器IP
    target_ip = input(f"请输入服务器IP (默认 {DEFAULT_HOST}): ").strip()
    if not target_ip:
        target_ip = DEFAULT_HOST

    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    
    try:
        print(f"[连接] 正在连接到服务器 {target_ip}:{PORT} ...")
        client.connect((target_ip, PORT))
        print("[成功] 已连接到服务器！")
        
        # 接收并处理昵称请求 (服务器会发送 "请输入您的昵称: ")
        initial_prompt = client.recv(BUFFER_SIZE).decode(ENCODING)
        nickname = input(initial_prompt)
        client.send(nickname.encode(ENCODING))
        
        # 启动接收消息的线程
        receive_thread = threading.Thread(target=receive_messages, args=(client,))
        receive_thread.daemon = True
        receive_thread.start()
        
        print("--------------------------------")
        print("已进入聊天室。输入消息并回车发送。")
        print("输入 'quit' 或 'exit' 退出。")
        print("--------------------------------")
        print("> ", end="")
        
        # 主线程处理用户输入
        while True:
            msg = input()
            
            if msg.lower() in ['quit', 'exit']:
                print("[退出] 正在退出聊天室...")
                break
                
            if msg:
                client.send(msg.encode(ENCODING))
                print("> ", end="") # 重新打印提示符
                
    except ConnectionRefusedError:
        print(f"[错误] 无法连接到服务器。请确认服务器已启动且IP端口配置正确。")
    except KeyboardInterrupt:
        print("\n[退出] 用户强制退出。")
    except Exception as e:
        print(f"\n[错误] 发生异常: {e}")
    finally:
        client.close()

if __name__ == "__main__":
    start_client()
