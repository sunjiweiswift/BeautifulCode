#ifndef BUILDER_H
#define BUILDER_H

#include "product.h"

class Builder {
public:
    Builder() { product_ = new Product(); }
    virtual ~Builder() {}
    virtual void BuildPartA(){};
    virtual void BuildPartB(){};
    virtual void BuildPartC(){};
    Product* GetResult() { return product_; };

protected:
    Product* product_;
};

class ConcreteBuilder : public Builder {
public:
    virtual void BuildPartA() { product_->SetA("A Style"); }
    virtual void BuildPartB() { product_->SetB("B Style"); }
    virtual void BuildPartC() { product_->SetC("C Style"); }
};

#endif