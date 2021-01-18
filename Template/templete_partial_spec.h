#ifndef TEMPLETE_PATICAL_SPEC
#define TEMPLETE_PATICAL_SPEC
#include <iostream>

template <typename T, typename... Args>
class CallFunction_ {
public:
    T operator()(Args... args) {
        T ret;
        std::cout << "T" << std::endl;
        return ret;
    }
};

template <typename... Args>
class CallFunction_<long, Args...> {
public:
    long operator()(Args... args) {
        long ret;
        std::cout << "long" << std::endl;
        return ret;
    }
};

template <typename... Args>
class CallFunction_<int, Args...> {
public:
    int operator()(Args... args) {
        int ret;
        std::cout << "int" << std::endl;
        return ret;
    }
};

template <typename... Args>
class CallFunction_<char, Args...> {
public:
    char operator()(Args... args) {
        char ret;
        std::cout << "char" << std::endl;
        return ret;
    }
};
template <typename T, typename... Args>
T CallFunction(Args... args) {
    return CallFunction_<T, Args...>()(std::forward<Args>(args)...);
}

#endif