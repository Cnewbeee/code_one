import java.io.*;
import java.net.*;
import java.util.Scanner;
import java.nio.charset.StandardCharsets;

public class ChatClient {
    private static final String DEFAULT_HOST = "124.222.4.182";
    private static final int PORT = 12345;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("请输入服务器IP (默认 " + DEFAULT_HOST + "): ");
        String host = scanner.nextLine().trim();
        if (host.isEmpty()) {
            host = DEFAULT_HOST;
        }

        try {
            System.out.println("[连接] 正在连接到服务器 " + host + ":" + PORT + " ...");
            Socket socket = new Socket(host, PORT);
            System.out.println("[成功] 已连接到服务器！");

            InputStream in = socket.getInputStream();
            OutputStream out = socket.getOutputStream();

            // 1. 接收昵称提示
            byte[] buffer = new byte[1024];
            int len = in.read(buffer);
            if (len > 0) {
                String prompt = new String(buffer, 0, len, StandardCharsets.UTF_8);
                System.out.print(prompt);
                
                String nickname = scanner.nextLine();
                out.write(nickname.getBytes(StandardCharsets.UTF_8));
                out.flush();
            }

            // 2. 启动接收消息线程
            Thread receiveThread = new Thread(() -> {
                try {
                    byte[] buf = new byte[1024];
                    int length;
                    while ((length = in.read(buf)) != -1) {
                        String message = new String(buf, 0, length, StandardCharsets.UTF_8);
                        // 使用 \r 清除当前行提示符，打印消息，然后重新打印提示符
                        System.out.print("\r" + message + "\n> ");
                    }
                } catch (IOException e) {
                    // Socket closed or error
                } finally {
                    System.out.println("\n[系统] 与服务器的连接已断开。");
                    System.exit(0);
                }
            });
            receiveThread.setDaemon(true);
            receiveThread.start();

            System.out.println("--------------------------------");
            System.out.println("已进入聊天室。输入消息并回车发送。");
            System.out.println("输入 'quit' 或 'exit' 退出。");
            System.out.println("--------------------------------");
            System.out.print("> ");

            // 3. 发送消息循环
            while (scanner.hasNextLine()) {
                String msg = scanner.nextLine();
                if ("quit".equalsIgnoreCase(msg) || "exit".equalsIgnoreCase(msg)) {
                    System.out.println("[退出] 正在退出聊天室...");
                    break;
                }
                if (!msg.isEmpty()) {
                    out.write(msg.getBytes(StandardCharsets.UTF_8));
                    out.flush();
                    System.out.print("> ");
                }
            }
            
            socket.close();

        } catch (UnknownHostException e) {
            System.out.println("[错误] 无法找到服务器: " + host);
        } catch (IOException e) {
            System.out.println("[错误] 无法连接到服务器: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }
}
