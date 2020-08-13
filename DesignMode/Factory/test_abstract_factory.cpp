#include "abstract_factory.h"

int main()
{
    AbstractFactory* factory1 = new ConcreteFactory1();
    AbstractFactory* factory2 = new ConcreteFactory2();
    AbstractProductA* productA1 = factory1->CreateProductA();
    AbstractProductB* productB1 = factory1->CreateProductB();
    AbstractProductA* productA2 = factory2->CreateProductA();
    AbstractProductB* productB2 = factory2->CreateProductB();
    productA1->Use();
    productB1->Use();
    productA2->Use();
    productB2->Use();
    delete factory1;
    delete factory2;
    delete productA1;
    delete productB1;
    delete productA2;
    delete productB2;
    return 0;
}