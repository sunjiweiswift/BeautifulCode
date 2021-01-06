#include "union_find.h"

int main()
{
    UnionFind<int> unionFind;
    unionFind.Union(0, 1);
    unionFind.Union(0, 2);
    return 0;
}