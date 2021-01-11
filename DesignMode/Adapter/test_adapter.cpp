#include "adaptee.h"
#include "adapter.h"

int main() {
    Adaptee* adaptee = new Adaptee();
    Target* target = new Adapter(adaptee);
    target->Request();
    delete adaptee;
    delete target;
    return 0;
}