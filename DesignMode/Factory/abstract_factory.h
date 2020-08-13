#ifndef CREATE_FACTORY_H
#define CREATE_FACTORY_H

#include <iostream>

// ProductA
class AbstractProductA {
public:
    virtual ~AbstractProductA() {};
    virtual void Use() = 0;
};

class ProductA1 : public AbstractProductA {
public:
    void Use() override
    {
        std::cout << "Use ProductA1" << std::endl;
    }
};

class ProductA2 : public AbstractProductA {
public:
    void Use() override
    {
        std::cout << "Use ProductA2" << std::endl;
    }
};
// ProductB
class AbstractProductB {
public:
    virtual ~AbstractProductB() {};
    virtual void Use() = 0;
};

class ProductB1 : public AbstractProductB {
public:
    void Use() override
    {
        std::cout << "Use ProductB1" << std::endl;
    }
};

class ProductB2 : public AbstractProductB {
public:
    void Use() override
    {
        std::cout << "Use ProductB2" << std::endl;
    }
};
// AbstractFactory
class AbstractFactory {
private:
    /* data */
public:
    virtual ~AbstractFactory() {};
    virtual AbstractProductA* CreateProductA() = 0;
    virtual AbstractProductB* CreateProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* CreateProductA() override
    {
        return new ProductA1();
    };
    AbstractProductB* CreateProductB() override
    {
        return new ProductB1();
    };
};

class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* CreateProductA() override
    {
        return new ProductA2();
    };
    AbstractProductB* CreateProductB() override
    {
        return new ProductB2();
    };
};

#endif