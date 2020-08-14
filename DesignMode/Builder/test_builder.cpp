#include "director.h"

int main()
{
    ConcreteBuilder* builder = new ConcreteBuilder();
    Director director;
    director.SetBuilder(builder);
    Product* product = director.Constuct();
    product->Show();
    delete builder;
    delete product;
    return 0;
}