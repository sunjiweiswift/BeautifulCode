#ifndef FACTORY_FUNCTION_H
#define FACTORY_FUNCTION_H
#include "product.h"

class AbstractCreator {
public:
    virtual ~AbstractCreator();
    virtual AbstractProduct* Create() = 0;
};

class CreatorA : public AbstractCreator {
public:
    AbstractProduct* Create() override
    {
        return new ProductA();
    }
};

class CreatorB : public AbstractCreator {
public:
    AbstractProduct* Create() override
    {
        return new ProductB();
    }
};

#endif