#include <iostream>

#include "trie.h"

using namespace std;

int main() {
    Trie* trie = new Trie;
    trie->Insert("harshita");
    trie->Insert("harsh");
    trie->Insert("sharma");
    trie->Insert("harry");
    string prefix = "ha";
    cout << trie->CountPrefix(prefix) << endl;
    delete trie;
    return 0;
}