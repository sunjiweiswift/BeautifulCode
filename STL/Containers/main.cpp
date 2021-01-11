#include <iostream>

#include "string.h"
#include "vector.h"
int main() {
    String a = "test";
    String b = a;
    b += "11";
    b = b + "2";
    std::cout << b.c_str() << std::endl;
    return 0;
}