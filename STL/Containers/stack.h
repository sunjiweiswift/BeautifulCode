#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
public:
    Stack() : top_(nullptr), size_(0) {}
    ~Stack() { Clear(); }
    void Push(const T& data) {
        StackNode* newNode = new StackNode(data, top_);
        size_++;
    }
    T Top() const {
        if (Empty()) {
            T t;
            return t;
        }
        return top_->data;
    }
    void Pop() {
        if (!Empty()) {
            StackNode* tmp = top_;
            top_ = top_->next;
            size_--;
            delete tmp;
        }
    }
    size_t Size() const { return size_; }
    bool Empty() const { return size_ > 0 ? true : false; }
    void Clear() {
        while (top_) {
            StackNode* tmp = top_;
            top_ = top_->next;
            delete tmp;
        }
        size_ = 0;
    }

private:
    struct StackNode {
        StackNode(const T& data, StackNode* next) : data(data), next(next) {}
        T data;
        StackNode* next;
    };
    StackNode* top_;
    size_t size_;
};

#endif