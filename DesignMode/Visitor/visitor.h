#ifndef VISITOR_H
#define VISITOR_H

class ConcreteElementA;
class ConcreteElementB;
class Element;
class Visitor {
public:
    Visitor(std::string name)
        : name_(name) {};
    virtual void VisitConcreteElementA(ConcreteElementA* element) = 0;
    virtual void VisitConcreteElementB(ConcreteElementB* element) = 0;

protected:
    std::string name_;
};

#endif