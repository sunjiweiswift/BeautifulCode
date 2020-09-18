#include "lru_cache.h"
#include <iostream>

using namespace std;

int main()
{
    LRUCache<int, int> lruCache(2, -1);
    lruCache.PutValue(1, 1);
    lruCache.PutValue(2, 2);
    cout << lruCache.GetValue(1) << endl; // 返回  1
    lruCache.PutValue(3, 3); // 该操作会使得关键字 2 作废
    cout << lruCache.GetValue(2) << endl; // 返回 -1 (未找到)
    lruCache.PutValue(4, 4); // 该操作会使得关键字 1 作废
    cout << lruCache.GetValue(1) << endl; // 返回 -1 (未找到)
    cout << lruCache.GetValue(3) << endl; // 返回  3
    cout << lruCache.GetValue(4) << endl; // 返回  4

    return 0;
}