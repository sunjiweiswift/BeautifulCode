#ifndef VECTOR_H
#define VECTOR_H
template <typename T>
class Vector {
public:
    Vector() : data_(nullptr), capcity_(0), size_(0) {}
    Vector(int capcity) : capcity_(capcity), size_(0) { data_ = new T[capcity]; }
    Vector(const Vector& other) {
        if (this == other) {
            return;
        }
        data_ = new T[other.capacity()];
        for (size_t i = 0; i < other.capacity(); i++) {
            data_[i] = other[i];
        }
        capcity_ = other.capacity();
        size_ = other.size();
    }
    ~Vector() { delete[] data_; }
    void reverse(size_t capcity) {
        if (capcity_ < capcity) {
            T* data_tmp = new T[capcity];
            for (size_t i = 0; i < size_; i++) {
                data_tmp[i] = data_[i];
            }
            capcity_ = capcity;
            delete[] data_;
            data_ = data_tmp;
        }
    }
    void resize(size_t size) {
        if (size_ < size) {
            size_ = size;
            reverse(size * 2 + 1);
        }
    }
    T& operator[](size_t index) {
        if (index < size_) {
            return data_[index];
        } else {
            throw "Out of bounds Exception!";
        }
    }
    size_t size() const { return size_; }
    size_t capacity() const { return capcity_; }
    void push_back(const T value) {
        if (size_ == capcity_) {
            reverse(capcity_ * 2 + 1);
        }
        data_[size_] = value;
        size_++;
    }

private:
    T* data_;
    size_t capcity_;
    size_t size_;
};

#endif
