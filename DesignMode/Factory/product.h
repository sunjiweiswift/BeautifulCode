#ifndef PRODUCT_H
#define PRODUCT_H
class AbstractProduct {
public:
    virtual ~AbstractProduct() {};
    virtual void Operation() = 0;
};

class ProductA : public AbstractProduct {
public:
    void Operation() override { }
};

class ProductB : public AbstractProduct {
public:
    void Operation() override { }
};

#endif