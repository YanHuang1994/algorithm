#include "../include/ThreadPool.h"
#include <iostream>
#include <chrono>
#include <future>
#include <vector>

// 模拟一个费时任务
void heavyTask(int n) {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Task " << n << " completed." << std::endl;
}

// 回调函数，处理任务完成后的结果
void taskCallback(int result) {
    std::cout << "Callback: Task completed with result = " << result << std::endl;
}

// 同步执行任务
void executeSync() {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 10; ++i) {
        heavyTask(i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Sync execution time: " << elapsed.count() << " seconds." << std::endl;
}

// 使用线程池执行任务
void executeWithThreadPool() {
    ThreadPool pool(10); // 创建线程池，10 个线程

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::future<void>> results;

    for (int i = 0; i < 10; ++i) {
        results.push_back(pool.enqueue([i] { heavyTask(i); }, taskCallback));
    }

    for (auto& result : results) {
        result.get(); // 等待任务完成
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Execution time with ThreadPool: " << elapsed.count() << " seconds." << std::endl;
}

// 使用普通线程执行任务
void executeWithThreads() {
    std::vector<std::thread> threads;

    auto start = std::chrono::high_resolution_clock::now();

    // 创建多个线程并执行任务
    for (int i = 0; i < 10; ++i) {
        threads.push_back(std::thread([i] { heavyTask(i); }));
    }

    // 等待所有线程完成
    for (auto& t : threads) {
        t.join();
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Execution time with multiple threads (without thread pool): " << elapsed.count() << " seconds." << std::endl;
}

int main() {
    std::cout << "Starting sync execution..." << std::endl;
    executeSync();

    std::cout << "\nStarting async execution with thread pool..." << std::endl;
    executeWithThreadPool();

    std::cout << "\nStarting async execution with thread only..." << std::endl;
    executeWithThreads();

    return 0;
}
