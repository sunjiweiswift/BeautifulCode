#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H
template <typename T>
class UniquePtr {
public:
    explicit UniquePtr(T* ptr = nullptr)
        : ptr_(ptr)
    {
    }
    ~UniquePtr()
    {
        if (this->ptr_ != nullptr) {
            delete this->ptr_;
        }
    }
    // Cannot have a copy constructor
    UniquePtr(const UniquePtr& other) = delete;
    UniquePtr operator=(const UniquePtr& other) = delete;
    // Move constructor
    UniquePtr(UniquePtr&& other)
        : ptr_(other.ptr_)
    {
        other.ptr_ = nullptr;
    }
    UniquePtr operator=(UniquePtr&& other)
    {
        if (other != *this) {
            if (this->ptr_ == nullptr) {
                delete this->ptr_;
            }
            this->ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }
        return *this;
    }
    T& operator*() const
    {
        return *this->ptr_;
    }
    T* operator->() const
    {
        return this->ptr_;
    }

private:
    T* ptr_;
};
#endif