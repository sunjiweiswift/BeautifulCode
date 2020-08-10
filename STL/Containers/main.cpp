#include "vector.h"
#include "string.h"
#include <iostream>
int main() {
    String a = "test";
    String b = a;
    b += "11";
    b = b + "2";
    std::cout << b.c_str() << std::endl;
    return 0;
}