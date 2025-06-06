# 内网通信程序使用说明

## 功能概述
实现Windows环境下局域网内两台计算机的TCP通信

## 程序组成
- server.cpp/server.exe - 服务端程序
- client.cpp/client.exe - 客户端程序

## 单机测试
1. 启动服务端：
   ```
   cd C++/内网通信
   server.exe
   ```
2. 启动客户端：
   ```
   cd C++/内网通信
   client.exe
   ```

## 跨计算机通信设置

### 服务端配置
1. 修改server.cpp中绑定地址：
   ```cpp
   serverAddr.sin_addr.s_addr = INADDR_ANY; // 允许所有网络接口
   ```
2. 确保服务端防火墙允许8080端口入站

### 客户端配置
1. 修改client.cpp中连接地址：
   ```cpp
   inet_pton(AF_INET, "192.168.1.100", &serverAddr.sin_addr); // 改为服务端实际IP
   ```
2. 获取服务端IP：
   - 服务端计算机上执行`ipconfig`，查看IPv4地址

### 通信测试
1. 服务端计算机：
   ```
   server.exe
   ```
2. 客户端计算机：
   ```
   client.exe
   ```
3. 在客户端输入消息，服务端会回显相同内容

## 注意事项
1. 确保两台计算机在同一局域网
2. 如果通信失败，检查：
   - 防火墙设置
   - IP地址是否正确
   - 网络连接是否正常
3. 可修改端口号(需同时修改服务端和客户端)
