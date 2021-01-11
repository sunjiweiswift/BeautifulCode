#include <iostream>

#include "union_find.h"

using namespace std;

int main() {
    UnionFind<int> unionFind;
    unionFind.Union(5, 2);
    unionFind.Union(1, 2);
    unionFind.Union(3, 5);
    unionFind.Union(0, 4);
    for (size_t i = 0; i < 6; i++) {
        cout << i << " parent is :" << unionFind.Find(i) << endl;
    }

    return 0;
}