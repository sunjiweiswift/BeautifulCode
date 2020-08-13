#ifndef CONTEXT_H
#define CONTEXT_H

#include "strategy.h"

class Context {
public:
    Context() { }

    virtual ~Context()
    {
        strategy_ = nullptr;
    }

    void SetStrategy(Strategy* strategy)
    {
        strategy_ = strategy;
    }

    void Algorithm()
    {
        strategy_->Algorithm();
    };

private:
    Strategy* strategy_;
};

#endif