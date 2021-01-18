#include <string>

#include "templete_partial_spec.h"

int main() {
    CallFunction<char>(1, 2, 3);
    CallFunction<int>(1, 2, 3);
    CallFunction<long>(1, 2, 3);
    CallFunction<std::string>(1, 2, 3);
    return 0;
}