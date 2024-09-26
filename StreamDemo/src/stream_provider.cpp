// stream_provider.cpp
#include <iostream>
#include <cstring>
#include "../include/stream_provider.h"  // 引入头文件

// 函数指针变量，用于保存回调函数
StreamCallback callback = NULL;  // 使用 NULL 而非 nullptr

// 动态库暴露的接口，用于注册回调函数
extern "C" void registerStreamCallback(StreamCallback cb) {
    callback = cb;
}

// 模拟产生码流数据并通过回调函数传递给服务端
extern "C" void startStream() {
    if (callback == NULL) {  // 使用 NULL 检查是否注册了回调函数
        std::cerr << "Error: No callback registered!" << std::endl;
        return;
    }

    // 模拟获取到的数据流，实际应用中可能是视频或音频数据
    const char* streamData = "Simulated stream data...";
    int dataSize = std::strlen(streamData);

    // 通过回调函数传递数据
    std::cout << "StreamProvider: Sending stream data to server..." << std::endl;
    callback(streamData, dataSize);  // 调用回调函数，将数据传递给服务端
}
