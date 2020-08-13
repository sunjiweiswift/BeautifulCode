#ifndef BUILDER_H
#define BUILDER_H

#include <iostream>
#include <string>

class Product {
public:
    void SetA(std::string str)
    {
        a_ = str;
    }
    void SetB(std::string str)
    {
        b_ = str;
    }
    void SetC(std::string str)
    {
        c_ = str;
    }
    void Show()
    {
        std::cout << "product has" << a_ << b_ << c_ << std::endl;
    }

private:
    std::string a_;
    std::string b_;
    std::string c_;
};

class Builder {
public:
    Builder()
    {
        product_ = new Product();
    }
    virtual ~Builder() { }
    virtual void BuildPartA() {};
    virtual void BuildPartB() {};
    virtual void BuildPartC() {};
    Product* GetResult()
    {
        return product_;
    };

protected:
    Product* product_;
};

class ConcreteBuilder : public Builder {
public:
    virtual void BuildPartA()
    {
        product_->SetA("A Style");
    }
    virtual void BuildPartB()
    {
        product_->SetB("B Style");
    }
    virtual void BuildPartC()
    {
        product_->SetC("C Style");
    }
};

class Director {
public:
    void SetBuilder(Builder* builder)
    {
        builder_ = builder;
    }
    Product* Constuct()
    {
        builder_->BuildPartA();
        builder_->BuildPartB();
        builder_->BuildPartC();
        return builder_->GetResult();
    }

private:
    Builder* builder_;
};

#endif