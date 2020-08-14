#ifndef ADAPTEE_H
#define ADAPTEE_H

#include <iostream>

class Adaptee {
public:
    void SpecificRequest()
    {
        std::cout << "Adaptee SpecificRequest" << std::endl;
    }
};

#endif