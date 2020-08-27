#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include "blocking_queue.h"
#include <atomic>
#include <functional>
#include <thread>
#include <vector>

#define THREAD_POOL_MAX_TASKS 2

class ThreadPool {
    using TaskFunc = std::function<void()>;
    using Task = std::pair<uint32_t, TaskFunc>;

public:
    ThreadPool(size_t threadNum = 1)
        : threadNum_(threadNum)
        , activeNum_(0)
        , stop_(false)
    {
    }
    ~ThreadPool()
    {
    }
    bool Init()
    {
        for (size_t i = 1; i < threadNum_; i++) {
            size_t threadIndex = i;
            workers_.emplace([this]() {
                int  a =1;
                //     while (!stop_) {

                //         // while (activeNum_ > 0) {
                //         //     for (size_t j = 0; j < THREAD_POOL_MAX_TASKS; j++) {
                //         //         if (*tasks_[i].second[threadIndex]) {
                //         //             tasks_[i].first.first(threadIndex);
                //         //             {
                //         //                 *tasks_[i].second[threadIndex] = false;
                //         //             }
                //         //         }
                //         //     }
                //         // }
                //     }
            });
        }
    }

private:
    size_t threadNum_;
    std::atomic_int activeNum_ = { 0 };
    std::atomic<bool> stop_;
    // std::vector<std::pair<TASK, std::vector<std::atomic_bool*>>> tasks_;
    BlockingQueue<Task> taskQueue_;
    std::vector<std::thread> workers_;
};

#endif