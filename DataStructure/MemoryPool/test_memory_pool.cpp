#include <iostream>

#include "memory_pool.h"

class Object {
public:
    Object(int x);
    ~Object();
    void* operator new(size_t size);
    void operator delete(void* ptr);

    int data;
};

MemoryPool<sizeof(Object), 3> gMemoryPool;

Object::Object(int x) : data(x) {
    std::cout << "Contruct Object" << std::endl;
}

Object::~Object() {
    std::cout << "Destruct Object" << std::endl;
}

void* Object::operator new(size_t size) {
    return gMemoryPool.Allocate();
}
void Object::operator delete(void* ptr) {
    gMemoryPool.Free(ptr);
}

int main() {
    Object* object1 = new Object(1);
    std::cout << "object1" << object1 << " " << object1->data << std::endl;
    Object* object2 = new Object(2);
    std::cout << "object2" << object2 << " " << object2->data << std::endl;
    Object* object3 = new Object(3);
    std::cout << "object3" << object3 << " " << object3->data << std::endl;
    Object* object4 = new Object(4);
    std::cout << "object4" << object4 << " " << object4->data << std::endl;
    Object* object5 = new Object(5);
    std::cout << "object5" << object5 << " " << object5->data << std::endl;
    Object* object6 = new Object(6);
    std::cout << "object6" << object6 << " " << object6->data << std::endl;
    delete object1;
    delete object2;
    delete object3;
    delete object4;
    delete object5;
    delete object6;

    return 0;
}