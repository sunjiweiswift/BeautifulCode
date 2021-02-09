#ifndef TEMPLETE_PATICAL_SPEC
#define TEMPLETE_PATICAL_SPEC

#include <iostream>
#include <string>

void Print() {
    std::cout << "End" << std::endl;
}

template <typename T, typename... Args>
void Print(T head, Args... reset) {
    std::cout << head << std::endl;
    Print(reset...);
}

template <typename R, typename... Args>
class CallFunction_ {
public:
    R operator()(std::string type, Args... args) {
        R ret;
        std::cout << type << std::endl;
        Print(args...);
        return ret;
    }
};

template <typename... Args>
class CallFunction_<long, Args...> {
public:
    long operator()(std::string type, Args... args) {
        long ret;
        std::cout << type << std::endl;
        Print(args...);
        return ret;
    }
};

template <typename... Args>
class CallFunction_<int, Args...> {
public:
    int operator()(std::string type, Args... args) {
        int ret;
        std::cout << type << std::endl;
        Print(args...);
        return ret;
    }
};

template <typename... Args>
class CallFunction_<char, Args...> {
public:
    char operator()(std::string type, Args... args) {
        char ret;
        std::cout << type << std::endl;
        Print(args...);
        return ret;
    }
};

template <typename R, typename... Args>
R CallFunction(std::string type, Args... args) {
    return CallFunction_<R, Args...>()(type, std::forward<Args>(args)...);
}

#endif