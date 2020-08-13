#ifndef CREATE_FACTORY_H
#define CREATE_FACTORY_H
#include "product.h"

class ProductA1 : public ProductA {
public:
    void Operation() override { }
};

class ProductA2 : public ProductA {
public:
    void Operation() override { }
};

class ProductB1 : public ProductB {
public:
    void Operation() override { }
};

class ProductB1 : public ProductB {
public:
    void Operation() override { }
};

class AbstractFactory {
private:
    /* data */
public:
    virtual ~AbstractFactory();
    virtual ProductA* CreateProductA() = 0;
    virtual ProductB* CreateProductB() = 0;
};

class CreateFactory1 : public AbstractFactory {
public:
    ProductA* CreateProductA() override
    {
        return new ProductA1;
    };
    ProductB* CreateProductB() override
    {
        return new ProductB1;
    };
};

class CreateFactory2 : public AbstractFactory {
public:
    ProductA* CreateProductA() override
    {
        return new ProductA2;
    };
    ProductB* CreateProductB() override
    {
        return new ProductB2;
    };
};

#endif