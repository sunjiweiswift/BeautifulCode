#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

class Product {
public:
    void SetA(std::string str) { a_ = str; }
    void SetB(std::string str) { b_ = str; }
    void SetC(std::string str) { c_ = str; }
    void Show() { std::cout << "product has" << a_ << b_ << c_ << std::endl; }

private:
    std::string a_;
    std::string b_;
    std::string c_;
};

#endif