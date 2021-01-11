#ifndef _CONCRETE_ELEMENT_H
#define _CONCRETE_ELEMENT_H
#include <iostream>

#include "element.h"
class ConcreteElementA : public Element {
public:
    ConcreteElementA(std::string name) : Element(name) {}

    void Accept(Visitor* visitor) override { visitor->VisitConcreteElementA(this); }

    const std::string GetName() const { return name_; }

    const std::string GetValueA() const { return valA_; }
    const std::string GetValueB() const { return valB_; }

private:
    std::string valA_ = "valA";
    std::string valB_ = "valB";
};

class ConcreteElementB : public Element {
public:
    ConcreteElementB(std::string name) : Element(name) {}

    void Accept(Visitor* visitor) override { visitor->VisitConcreteElementB(this); }
    const std::string GetValueA() const { return valA_; }
    const std::string GetValueB() const { return valB_; }

private:
    std::string valA_ = "valA";
    std::string valB_ = "valB";
};

#endif