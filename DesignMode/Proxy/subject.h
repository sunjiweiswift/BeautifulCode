#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>

class Subject {
public:
    virtual ~Subject() {}
    virtual void Request() = 0;
};

class RealSubJect : public Subject {
public:
    void Request() override { std::cout << "Real Request" << std::endl; }
};

#endif