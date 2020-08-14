#include "abstraction.h"

int main()
{
    Implementor* implementorA = new ConcreteImplementorA();
    Implementor* implementorB = new ConcreteImplementorB();
    Abstraction* abstrationA = new RefinedAbstraction(implementorA);
    Abstraction* abstrationB = new RefinedAbstraction(implementorB);
    abstrationA->Operation();
    abstrationB->Operation();
    delete implementorA;
    delete implementorB;
    delete abstrationA;
    delete abstrationB;
    return 0;
}