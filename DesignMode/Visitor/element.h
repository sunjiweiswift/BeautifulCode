#ifndef ELEMENT_H
#define ELEMENT_H
#include <string>

class Visitor;

class Element {
public:
    Element(std::string name)
        : name_(name)
    {
    }
    virtual void Accept(Visitor visitor) const = 0;

private:
    std::string name_;
    int val;
};

class ElementA : public Element{
private:
    /* data */
public:
    ElementA(std::string name)
        : Element(name)
    {
    }

    void Accept(Visitor visitor) const override {
        visitor.Visit(this);
    }

    int GetVal()
    {
        return 1;
    }
};

#endif