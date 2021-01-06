#ifndef UNION_FIND_H
#define UNION_FIND_H
#include <vector>
using namespace std;

template <typename Type>
class UnionFind {
public:
    UnionFind(int n);
    ~UnionFind();

private:
    int count_ = 0;
    vector<T> variables_;
};

#endif