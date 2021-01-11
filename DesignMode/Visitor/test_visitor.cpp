#include "concrete_element.h"
#include "concrete_visitor.h"
#include "object_structure.h"

int main() {
    ObjectStructure* object = new ObjectStructure;

    ConcreteElementA* elementA = new ConcreteElementA("ConcreteElementA");
    ConcreteElementB* elementB = new ConcreteElementB("ConcreteElementB");

    object->Attach(elementA);
    object->Attach(elementB);

    ConcreteVisitorA* visitorA = new ConcreteVisitorA("visitorA");
    ConcreteVisitorB* visitorB = new ConcreteVisitorB("visitorB");

    object->Accept(visitorA);
    object->Accept(visitorB);

    return 0;
}