#ifndef SIMPLE_FACTORY_H
#define SIMPLE_FACTORY_H
#include "product.h"
class SimpleFactory {
public:
    SimpleFactory();
    ~SimpleFactory();
    AbstractProduct* CreateProduct(int id)
    {
        AbstractProduct* product = nullptr;
        switch (id) {
        case 0:
            product = new ProductA();
            break;
        case 1:
            product = new ProductB();
            break;
        }
        return product;
    }
};

#endif