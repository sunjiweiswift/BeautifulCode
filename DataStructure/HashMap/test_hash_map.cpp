#include <iostream>
#include <string>

#include "hash_map.h"

using namespace std;

//首先要定义hash函数与比较函数
class HashFunc {
public:
    int operator()(const string& key) {
        int hash = 0;
        for (int i = 0; i < key.length(); ++i) {
            hash = hash << 7 ^ key[i];
        }
        return (hash & 0x7FFFFFFF);
    }
};

class EqualKey {
public:
    bool operator()(const string& A, const string& B) {
        if (A.compare(B) == 0)
            return true;
        else
            return false;
    }
};

int main() {
    HashMap<string, string, HashFunc, EqualKey> hashmap(100);

    hashmap.insert("hello", "world");
    hashmap.insert("why", "dream");
    hashmap.insert("c++", "good");
    hashmap.insert("welcome", "haha");

    cout << "after insert:" << endl;
    cout << hashmap.find("welcome").c_str() << endl;
    cout << hashmap.find("c++").c_str() << endl;
    cout << hashmap["why"].c_str() << endl;
    cout << hashmap["hello"].c_str() << endl;

    if (hashmap.del("hello")) cout << "remove is ok" << endl; //remove is ok
    cout << hashmap.find("hello").c_str() << endl;            //not exist print NULL

    hashmap["why"] = "love";
    cout << hashmap["why"].c_str() << endl;
    return 0;
}