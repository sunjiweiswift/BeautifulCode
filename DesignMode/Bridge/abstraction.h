#ifndef ABSTRACTION_H
#define ABSTRACTION_H
#include "implementor.h"
class Abstraction {
public:
    Abstraction();
    Abstraction(Implementor* Implementor)
        : Implementor_(Implementor)
    {
    }
    virtual ~Abstraction() { }
    virtual void Operation() = 0;

protected:
    Implementor* Implementor_;
};

class RefinedAbstraction : public Abstraction {
public:
    RefinedAbstraction(Implementor* Implementor)
        : Abstraction(Implementor)
    {
    }
    void Operation() override
    {
        std::cout << "do something else, and then " << std::endl;
        Implementor_->OperationImp();
    }
};
#endif