#ifndef STRATEGY_H
#define STRATEGY_H
#include <iostream>

class Strategy {
public:
    virtual ~Strategy() {};
    virtual void Algorithm() = 0;
};

class ConcreteStrategyA : public Strategy {
public:
    void Algorithm() override
    {
        std::cout << "StrateA Algorithm" << std::endl;
    }
};

class ConcreteStrategyB : public Strategy {
public:
    void Algorithm() override
    {
        std::cout << "StrateB Algorithm" << std::endl;
    }
};
#endif