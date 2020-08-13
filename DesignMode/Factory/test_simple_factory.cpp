#include "simple_factory.h"
#include <string>
int main()
{
    SimpleFactory* factory = new SimpleFactory();
    Product* productA = factory->CreateProduct("A");
    Product* productB = factory->CreateProduct("B");
    productA->Use();
    productB->Use();
    delete productA;
    delete productB;
    delete factory;
    return 0;
}