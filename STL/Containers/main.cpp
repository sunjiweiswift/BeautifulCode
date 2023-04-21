#include <iostream>

#include "string.h"
#include "vector.h"
int main() {
    String a = "test";
    String b = a;
    b += "11";
    b = b + "2";
    std::cout << b.c_str() << std::endl;

    Vector<String> c;
    c.push_back(a);
    c.push_back(a);
    for (size_t i = 0; i < c.size(); i++) {
        std::cout << c[i].c_str() << std::endl;
    }

    return 0;
}
