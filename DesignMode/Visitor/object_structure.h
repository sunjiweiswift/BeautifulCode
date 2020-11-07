#ifndef OBJECT_STRUCTURE_H
#define OBJECT_STRUCTURE_H
#include <list>

#include "element.h"
#include "visitor.h"

class ObjectStructure {
public:
    void Attach(Element* element)
    {
        list_.push_back(element);
    }
    void Detach(Element* element)
    {
        list_.remove(element);
    }
    void Accept(Visitor* visitor)
    {
        std::list<Element*>::iterator iter;
        for (iter = list_.begin(); iter != list_.end(); iter++) {
            if (*iter != nullptr) {
                (*iter)->Accept(visitor);
            }
        }
    }

private:
    std::list<Element*> list_;
};

#endif