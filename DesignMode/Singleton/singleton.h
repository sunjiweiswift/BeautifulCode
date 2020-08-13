#ifndef SINGLETON_H
#define SINGLETON_H

#include <mutex>

template <typename T>
class Singleton {
public:
    static T* GetInstance()
    {
        if (instance_ == nullptr) {
            std::lock_guard<std::mutex> guard(mutex_);
            if (instance_ == nullptr) {
                instance_ = new (std::nothrow) T();
            }
        }
        return instance_;
    }

    static bool Destroy()
    {
        std::lock_guard<std::mutex> guard(mutex_);
        if (instance_ != nullptr) {
            delete instance_;
            instance_ = nullptr;
            return true;
        }
        return false;
    }

private:
    Singleton() = default;
    ~Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    static T* instance_;
    static std::mutex mutex_;
};

template <typename T>
T* Singleton<T>::instance_ = nullptr;

template <typename T>
std::mutex Singleton<T>::mutex_;
#endif