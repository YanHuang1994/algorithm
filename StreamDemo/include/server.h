// ../include/server.h
#ifndef SERVER_H
#define SERVER_H

// 引入动态库中的回调函数声明
#include "../include/stream_provider.h"

// 回调函数声明
void streamCallback(const char* streamData, int size);

#endif // SERVER_H
