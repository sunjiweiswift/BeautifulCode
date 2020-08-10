#ifndef STRING_H
#define STRING_H

#include <cstddef>
#include <cstring>

class String {
public:
    String(const char* str = nullptr)
    {
        if (str == nullptr) {
            length_ = 0;
            data_ = new char[1];
            *data_ = '\0';
        } else {
            length_ = strlen(str);
            data_ = new char[length_ + 1];
            strcpy(data_, str);
        }
    }
    String(const String& other)
    {
        this->length_ = other.Size();
        this->data_ = new char[length_ + 1];
        strcpy(this->data_, other.c_str());
    }
    ~String()
    {
        delete[] data_;
        data_ = nullptr;
        length_ = 0;
    }

    String operator+(const String& str) const
    {
        String newString;
        newString.length_ = length_ + str.Size();
        newString.data_ = new char[newString.length_ + 1];
        strcpy(newString.data_, data_);
        strcat(newString.data_, str.data_); //字符串拼接函数，即将str内容复制到StringNew内容后面
        return newString;
    }

    String& operator=(const String& other)
    {
        if (this == &other) {
            return *this;
        }
        delete[] data_;
        length_ = other.Size();
        data_ = new char[length_ + 1];
        strcpy(data_, other.c_str());
        return *this;
    }

    String& operator+=(const String& str)
    {
        length_ += str.Size();
        char* newData = new char[length_ + 1];
        strcpy(newData, data_);
        delete[] data_;
        strcat(newData, str.c_str());
        data_ = newData;
        return *this;
    }

    //重载==
    bool operator==(const String& other) const
    {
        if (length_ != other.length_) {
            return false;
        }
        return strcmp(data_, other.data_) ? false : true;
    }

    //重载[]
    char& operator[](int n) const //str[n]表示第n+1个元素
    {
        if (n >= length_) {
            return data_[length_ - 1]; //错误处理
        } else {
            return data_[n];
        }
    }

    size_t Size() const
    {
        return this->length_;
    }
    const char* c_str() const
    {
        return data_;
    }

private:
    char* data_;
    size_t length_;
};

#endif