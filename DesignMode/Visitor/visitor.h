#ifndef VISITOR_H
#define VISITOR_H
#include <iostream>
#include <string>

class ElementA;

class Visitor {
public:
    Visitor(std::string name)
        : visitorName_(name) {};
    virtual void visit(ElementA element) = 0;

private:
    std::string visitorName_;
};

class VisitorA {
public:
    VisitorA(std::string name)
        : Visitor(name)
    {
    }
    void Visit(ElementA element) {
        std::cout << "VisitorA:" << "ElementA-val:" << element.GetVal() << std::endl;
    }
};

#endif