template <typename T>
class ShardPtr {
public:
    ShardPtr(T* ptr = nullptr)
        : ptr_(ptr)
    {
        if (ptr != nullptr) {
            refCount_ = new size_t(1);
        } else {
            refCount_ = new size_t(0);
        }
    }
    ~ShardPtr()
    {
        if (--(*this->refCount_) == 0 && ptr_ != nullptr) {
            delete this->ptr_;
            delete this->refCount_
        }
    }
    ShardPtr(const ShardPtr<T>& other) // Copy Constructor
    {
        if (this != &other) {
            this->ptr_ = other.ptr_;
            this->refCount_ = other.refCount_;
            (*this->refCount_)++;
        }
    }
    ShardPtr& operator=(const ShardPtr& ohter) // Copy Assignment operator
    {
        if (this == &other) {
            return *this;
        }
        if (--(*this->refCount_) == 0 && this->ptr_ != nullptr) {
            delete ptr_;
            delete refCount_;
        }
        ++*other.refCount_;
        this->ptr_ = ohter.ptr_;
        this->refCount_ = ohter.refCount_;
        return *this;
    }
    T& operator*()
    {
        if (this->refCount_ == 0) {
            return (T*)0;
        }
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
}