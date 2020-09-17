#include "lru_cache.h"
#include <iostream>
using namespace std;
int main()
{
    LRUCache<int, char> lru(3, 'z');
    lru.PutValue(1, 'a');
    lru.PutValue(2, 'b');
    lru.PutValue(3, 'c');
    lru.PutValue(4, 'd');
    for (size_t i = 1; i < 5; i++) {
        cout << lru.GetValue(i) << endl;
    }
    return 0;
}