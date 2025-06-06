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
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "socket creation failed" << std::endl;
        WSACleanup();
        return 1;
    }

    // 绑定IP和端口
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    inet_pton(AF_INET, "192.168.248.1", &serverAddr.sin_addr);
    serverAddr.sin_port = htons(8080);

    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "bind failed" << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // 监听连接
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "listen failed" << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Server is listening on port 8080..." << std::endl;

    // 接受客户端连接
    SOCKET clientSocket = accept(serverSocket, NULL, NULL);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "accept failed" << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Client connected" << std::endl;

    // 收发数据
    char recvBuf[1024];
    int recvResult;
    do {
        recvResult = recv(clientSocket, recvBuf, sizeof(recvBuf), 0);
        if (recvResult > 0) {
            std::cout << "Received: " << std::string(recvBuf, recvResult) << std::endl;
            
            // 回显收到的数据
            send(clientSocket, recvBuf, recvResult, 0);
        }
        else if (recvResult == 0) {
            std::cout << "Connection closing..." << std::endl;
        }
        else {
            std::cerr << "recv failed: " << WSAGetLastError() << std::endl;
            closesocket(clientSocket);
            WSACleanup();
            return 1;
        }
    } while (recvResult > 0);

    // 关闭连接
    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}