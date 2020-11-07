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
    virtual void Accept(Visitor* visitor) = 0;
    const std::string GetName() const
    {
        return name_;
    }

protected:
    std::string name_;
};

#endif