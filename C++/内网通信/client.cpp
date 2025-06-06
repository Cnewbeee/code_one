#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>

#pragma comment(lib, "ws2_32.lib")

int main() {
    // 初始化Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed" << std::endl;
        return 1;
    }

    // 创建socket
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "socket creation failed" << std::endl;
        WSACleanup();
        return 1;
    }

    // 设置服务器地址和端口
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    inet_pton(AF_INET, "192.168.248.1", &serverAddr.sin_addr);

    // 连接到服务器
    if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "connect failed" << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Connected to server. Type 'exit' to quit." << std::endl;

    // 通信循环
    char sendBuf[1024];
    char recvBuf[1024];
    int recvResult;

    do {
        // 获取用户输入
        std::cout << "> ";
        std::cin.getline(sendBuf, sizeof(sendBuf));

        // 发送数据
        if (send(clientSocket, sendBuf, (int)strlen(sendBuf), 0) == SOCKET_ERROR) {
            std::cerr << "send failed: " << WSAGetLastError() << std::endl;
            closesocket(clientSocket);
            WSACleanup();
            return 1;
        }

        // 检查是否退出
        if (strcmp(sendBuf, "exit") == 0) {
            break;
        }

        // 接收响应
        recvResult = recv(clientSocket, recvBuf, sizeof(recvBuf), 0);
        if (recvResult > 0) {
            std::cout << "Server response: " << std::string(recvBuf, recvResult) << std::endl;
        }
        else if (recvResult == 0) {
            std::cout << "Server closed connection" << std::endl;
            break;
        }
        else {
            std::cerr << "recv failed: " << WSAGetLastError() << std::endl;
            closesocket(clientSocket);
            WSACleanup();
            return 1;
        }
    } while (true);

    // 关闭连接
    closesocket(clientSocket);
    WSACleanup();

    return 0;
}