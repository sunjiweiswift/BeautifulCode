#ifndef CONCREATE_VISITOR_H
#define CONCREATE_VISITOR_H

#include <iostream>

#include "visitor.h"

class ConcreteVisitorA : public Visitor {
public:
    ConcreteVisitorA(std::string name) : Visitor(name) {}
    void VisitConcreteElementA(ConcreteElementA* element) override {
        std::cout << name_ << " Visit " << element->GetName() << " GetVal" << element->GetValueA()
                  << std::endl;
    }
    void VisitConcreteElementB(ConcreteElementB* element) override {
        std::cout << name_ << " Visit " << element->GetName() << " GetVal" << element->GetValueB()
                  << std::endl;
    }
};

class ConcreteVisitorB : public Visitor {
public:
    ConcreteVisitorB(std::string name) : Visitor(name) {}

    void VisitConcreteElementA(ConcreteElementA* element) override {
        std::cout << name_ << " Visit " << element->GetName() << " GetVal" << element->GetValueA()
                  << std::endl;
    }
    void VisitConcreteElementB(ConcreteElementB* element) override {
        std::cout << name_ << " Visit " << element->GetName() << " GetVal" << element->GetValueB()
                  << std::endl;
    }
};
#endif