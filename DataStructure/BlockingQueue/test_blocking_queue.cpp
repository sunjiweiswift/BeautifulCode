#include <iostream>

#include "blocking_queue.h"

int main() {
    BlockingQueue<int> que;
    que.Push(1);
    std::cout << "size:" << que.Size() << " " << que.Pop() << std::endl;
    return 0;
}