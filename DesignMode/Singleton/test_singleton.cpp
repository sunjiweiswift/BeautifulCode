#include "singleton.h"
#include <iostream>

class Test {
public:
    Test()
    {
        std::cout << "Test Constructor" << std::endl;
    }
    ~Test()
    {
        std::cout << "Test Destructor " << std::endl;
    }
};

int main()
{
    Test* ptr1 = Singleton<Test>::GetInstance();
    Test* ptr2 = Singleton<Test>::GetInstance();
    if (ptr1 == ptr2) {
        std::cout << "ptr1 == ptr2" << std::endl;
    }
    Singleton<Test>::Destroy();
    return 0;
}