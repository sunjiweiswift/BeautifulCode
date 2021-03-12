#include <string>

#include "templete_partial_spec.h"

int main() {
    CallFunction<char>("char", 2, 3);
    CallFunction<int>("int", 1, 2, 3);
    CallFunction<long>("long", 1, 2, 3);
    CallFunction<std::string>("string", 1, 2, 3);
    CallFunction<void>("void", 1, 2, 3);
    return 0;
}