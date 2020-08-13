#ifndef SINGLETON_H
#define SINGLETON_H
// 懒汉模式关键-使用时实例化 需要加锁
// 饿汉模式的关键-初始化即实例化 不需要加锁
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