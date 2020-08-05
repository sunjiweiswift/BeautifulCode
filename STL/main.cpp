#include "shared_ptr.h"
#include "unique_ptr.h"
#include <iostream>
#include <memory>
int main()
{
    ShardPtr<int> a(new int(1));
    UniquePtr<int> b(new int(2));
    std::shared_ptr<int> c(new int(3));
    std::cout << *a << std::endl;
    std::cout << *b << std::endl;
    std::cout << *c << std::endl;
    return 0;
}