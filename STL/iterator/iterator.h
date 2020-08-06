#ifndef ITERATOR_H
#define ITERATOR_H

// Iterator Base
class Iterator {
public:
    virtual ~Iterator() = default;
    virtual Iterator* CreateIterator(Aggregate* AggregatePtr) = 0;
};

class Aggregate {
private:
    /* data */
public:
    Aggregate(/* args */);
    ~Aggregate();
};

#endif