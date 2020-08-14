#ifndef ADAPT_H
#define ADAPT_H
class Target {
public:
    virtual ~Target() { }
    virtual void Request() = 0;
};

#endif