#ifndef BLOCKING_QUEUE_H
#define BLOCKING_QUEUE_H
#include <condition_variable>
#include <deque>
#include <mutex>

template <typename T>
class BlockingQueue {
public:
    BlockingQueue()
        : mutex_()
        , notEmpty_()
        , que_()
    {
    }

    ~BlockingQueue()
    {
        que_.clear();
    }
    void Push(const T& task)
    {
        {
            std::unique_lock<std::mutex> lock(mutex_);
            que_.push_back(task);
        }
        notEmpty_.notify_one(); // Out of lock call
    }

    void Push(T&& task)
    {
        {
            std::unique_lock<std::mutex> lock(mutex_);
            que_.push_back(std::move(task));
        }
        notEmpty_.notify_one();
    }

    T Pop()
    {
        std::unique_lock<std::mutex> lock(mutex_);
        notEmpty_.wait(lock, [this] { return !this->que_.empty(); });
        T task(std::move(que_.front()));
        que_.pop_front();
        return task;
    }
    size_t Size() const
    {
        std::unique_lock<std::mutex> lock(mutex_);
        return que_.size();
    }

private:
    BlockingQueue(const BlockingQueue&) = delete;
    BlockingQueue& operator=(const BlockingQueue&) = delete;

private:
    mutable std::mutex mutex_;
    std::condition_variable notEmpty_;
    std::deque<T> que_;
};

#endif