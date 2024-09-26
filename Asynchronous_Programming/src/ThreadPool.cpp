#include "../include/ThreadPool.h"

// 线程池构造函数，创建指定数量的工作线程
ThreadPool::ThreadPool(size_t threads) : stop(false) {
    for (size_t i = 0; i < threads; ++i) {
        workers.emplace_back([this] { workerThread(); });
    }
}

// 线程池析构函数，确保所有工作线程完成后退出
ThreadPool::~ThreadPool() {
    {
        std::unique_lock<std::mutex> lock(queueMutex);
        stop = true;
    }
    condition.notify_all();
    for (std::thread &worker : workers) {
        worker.join();
    }
}

// 向线程池中添加任务，并返回 std::future<void>
std::future<void> ThreadPool::enqueue(Task task, Callback callback) {
    auto packagedTask = std::make_shared<std::packaged_task<void()>>(task);

    std::future<void> result = packagedTask->get_future();
    {
        std::unique_lock<std::mutex> lock(queueMutex);
        if (stop) {
            throw std::runtime_error("enqueue on stopped ThreadPool");
        }
        tasks.emplace([packagedTask]() { (*packagedTask)(); }, callback);
    }

    condition.notify_one();
    return result;
}

// 工作线程函数，负责从任务队列中取任务并执行
void ThreadPool::workerThread() {
    while (true) {
        std::pair<Task, Callback> taskPair;
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            condition.wait(lock, [this] { return stop || !tasks.empty(); });
            if (stop && tasks.empty()) {
                return;
            }

            taskPair = std::move(tasks.front());
            tasks.pop();
        }

        // 执行任务
        taskPair.first();
        // 执行回调函数（假设返回 42）
        taskPair.second(42);
    }
}
