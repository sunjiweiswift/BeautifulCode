#ifndef SHARED_PTR_H
#define SHARED_PTR_H
template <typename T>
class SharedPtr {
public:
    SharedPtr(T* ptr = nullptr)
        : ptr_(ptr)
    {
        if (ptr != nullptr) {
            refCount_ = new int(1);
        } else {
            refCount_ = new int(0);
        }
    }
    ~SharedPtr()
    {
        if (--(*this->refCount_) == 0 && ptr_ != nullptr) {
            delete this->ptr_;
            delete this->refCount_;
        }
    }
    SharedPtr(const SharedPtr<T>& other) // Copy Constructor
    {
        if (this != &other) {
            this->ptr_ = other.ptr_;
            this->refCount_ = other.refCount_;
            (*this->refCount_)++;
        }
    }
    SharedPtr& operator=(const SharedPtr& other) // Copy Assignment operator
    {
        if (this == &other) {
            return *this;
        }
        if (--(*this->refCount_) == 0 && this->ptr_ != nullptr) {
            delete ptr_;
            delete refCount_;
        }
        ++*other.refCount_;
        this->ptr_ = other.ptr_;
        this->refCount_ = other.refCount_;
        return *this;
    }
    T& operator*()
    {
        return *this->ptr_;
    }
    T* operator->()
    {
        if (this->refCount_ == 0) {
            return 0;
        }
        return ptr_;
    }

private:
    T* ptr_;
    int* refCount_;
};
#endif