#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "builder.h"

class Director {
public:
    void SetBuilder(Builder* builder) { builder_ = builder; }
    Product* Constuct() {
        builder_->BuildPartA();
        builder_->BuildPartB();
        builder_->BuildPartC();
        return builder_->GetResult();
    }

private:
    Builder* builder_;
};

#endif