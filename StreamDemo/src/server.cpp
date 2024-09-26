// server.cpp
#include <iostream>
#include "../include/server.h"  // 引入头文件

// 服务端的回调函数，用于接收码流数据
void streamCallback(const char* streamData, int size) {
    std::cout << "Server: Received stream data of size " << size 
              << ". Data: " << streamData << std::endl;
}

int main() {
    // 注册回调函数
    registerStreamCallback(streamCallback);

    // 开始流传输（触发回调）
    startStream();

    return 0;
}
