#ifndef ADAPTER_H
#define ADAPTER_H

#include "adaptee.h"
#include "target.h"

class Adapter : public Target {
public:
    Adapter(Adaptee* adaptee) : adaptee_(adaptee) {}

    void Request() { adaptee_->SpecificRequest(); }

private:
    Adaptee* adaptee_;
};

#endif