#ifndef SIMPLE_FACTORY_H
#define SIMPLE_FACTORY_H

#include <iostream>

class Product {
public:
    virtual ~Product(){};
    virtual void Use() = 0;
};

class ConcreteProductA : public Product {
public:
    void Use() override { std::cout << "Use ConcreteProductA" << std::endl; }
};

class ConcreteProductB : public Product {
public:
    void Use() override { std::cout << "Use ConcreteProductB" << std::endl; }
};

class SimpleFactory {
public:
    Product* CreateProduct(std::string name) {
        Product* product = nullptr;
        if (name == "A") {
            return new ConcreteProductA();
        } else if (name == "B") {
            return new ConcreteProductB();
        }
    }
};

#endif