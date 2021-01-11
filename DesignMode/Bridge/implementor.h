#ifndef IMPLEMENTOR_H
#define IMPLEMENTOR_H

#include <iostream>

class Implementor {
public:
    virtual ~Implementor(){};
    virtual void OperationImp() = 0;
};

class ConcreteImplementorA : public Implementor {
public:
    void OperationImp() override { std::cout << "imp in ConcreteImplementorA style." << std::endl; }
};

class ConcreteImplementorB : public Implementor {
public:
    void OperationImp() override { std::cout << "imp in ConcreteImplementorB style." << std::endl; }
};

#endif