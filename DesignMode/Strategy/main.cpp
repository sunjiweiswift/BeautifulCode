#include "context.h"

int main()
{
    Strategy* strategyA = new ConcreteStrategyA();
    Context* context = new Context();
    context->SetStrategy(strategyA);
    context->Algorithm();
    Strategy* strategyB = new ConcreteStrategyB();
    context->SetStrategy(strategyB);
    context->Algorithm();
    delete strategyA;
    delete strategyB;
    delete context;
    return 0;
}