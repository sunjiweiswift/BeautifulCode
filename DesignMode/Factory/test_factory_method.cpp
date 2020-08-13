#include "factory_method.h"

int main()
{
    Factory* factoryA = new ConcreteFactoryA();
    Factory* factoryB = new ConcreteFactoryB();
    Product* productA = factoryA->FactoryMethod();
    Product* productB = factoryB->FactoryMethod();
    productA->Use();
    productB->Use();
    delete factoryA;
    delete factoryB;
    delete productA;
    delete productB;
    return 0;
}