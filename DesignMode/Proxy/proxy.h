#ifndef PROXY_H
#define PROXY_H

#include "subject.h"

class Proxy : public Subject {
public:
    Proxy() { realSubJect_ = new RealSubJect(); }
    ~Proxy() { delete realSubJect_; }
    void Request() override {
        ProRequest();
        realSubJect_->Request();
        AfterRequest();
    }

private:
    void AfterRequest() { std::cout << "Proxy AfterRequest" << std::endl; }
    void ProRequest() { std::cout << "Proxy PreRequest" << std::endl; }

private:
    RealSubJect* realSubJect_;
};

#endif
