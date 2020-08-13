#ifndef FACTORY_METHOD_H
#define FACTORY_METHOD_H

#include <iostream>

// Abstract Product
class Product {
public:
    virtual ~Product() {};
    virtual void Use() = 0;
};

class ConcreteProductA : public Product {
public:
    void Use() override
    {
        std::cout << "Use ConcreteProductA" << std::endl;
    }
};

class ConcreteProductB : public Product {
public:
    void Use() override
    {
        std::cout << "Use ConcreteProductB" << std::endl;
    }
};
// Abstract Factory
class Factory {
public:
    virtual ~Factory() {};
    virtual Product* FactoryMethod() = 0;
};

class ConcreteFactoryA : public Factory {
public:
    Product* FactoryMethod() override
    {
        return new ConcreteProductA();
    }
};

class ConcreteFactoryB : public Factory {
public:
    Product* FactoryMethod() override
    {
        return new ConcreteProductB();
    }
};

#endif