#include "lfu_cache.h"
#include <iostream>

using namespace std;

int main()
{
    // LFUCache<int, int> lfuCache(2, -1);
    // lfuCache.PutValue(1, 1);
    // lfuCache.PutValue(2, 2);
    // cout << lfuCache.GetValue(1) << endl; // 返回  1
    // lfuCache.PutValue(3, 3); // 该操作会使得关键字 2 作废
    // cout << lfuCache.GetValue(2) << endl; // 返回 -1 (未找到)
    // lfuCache.PutValue(4, 4); // 该操作会使得关键字 1 作废
    // cout << lfuCache.GetValue(1) << endl; // 返回 -1 (未找到)
    // cout << lfuCache.GetValue(3) << endl; // 返回  3
    // cout << lfuCache.GetValue(4) << endl; // 返回  4

    return 0;
}