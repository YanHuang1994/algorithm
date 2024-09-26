#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <iostream>

// 定义任务类型
using Task = std::function<void()>;
using Callback = std::function<void(int)>;

// 线程池类
class ThreadPool {
public:
    ThreadPool(size_t);
    ~ThreadPool();

    // 向线程池中添加任务，并返回 std::future<void>
    std::future<void> enqueue(Task task, Callback callback);

private:
    void workerThread(); // 工作线程

    std::vector<std::thread> workers;                  // 存储工作线程
    std::queue<std::pair<Task, Callback>> tasks;       // 任务队列，包括回调函数

    std::mutex queueMutex;                             // 任务队列的互斥锁
    std::condition_variable condition;                 // 条件变量，用于线程同步
    bool stop;                                         // 线程池停止标志
};

#endif // THREADPOOL_H
