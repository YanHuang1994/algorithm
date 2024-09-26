// ../include/stream_provider.h
#ifndef STREAM_PROVIDER_H
#define STREAM_PROVIDER_H

// 定义回调函数类型
typedef void (*StreamCallback)(const char* streamData, int size);

// 函数声明
extern "C" void registerStreamCallback(StreamCallback cb);
extern "C" void startStream();

#endif // STREAM_PROVIDER_H
