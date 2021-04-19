#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <unordered_map>

class Trie {
public:
    Trie() { root_ = new TrieNode(); };
    ~Trie() { delete root_; };

    void Insert(const std::string& word) {
        TrieNode* node = root_;
        for (char letter : word) {
            if (node->children[letter] == nullptr) {
                node->children[letter] = new TrieNode;
            }
            node = node->children[letter];
            node->prefixs++;
        }
        node->isEndOfWord = true;
    }

    bool Search(const std::string& word) {
        TrieNode* node = root_;
        for (char letter : word) {
            if (node->children[letter] == nullptr) {
                return false;
            }
            node = node->children[letter];
        }
        return node->isEndOfWord;
    }
    int CountPrefix(const std::string& word) {
        TrieNode* node = root_;
        for (char letter : word) {
            if (node->children[letter] == nullptr) {
                return 0;
            }
            node = node->children[letter];
        }
        return node->prefixs;
    }

private:
    struct TrieNode {
        TrieNode() {
            isEndOfWord = false;
            prefixs = 0;
        }
        ~TrieNode() {
            for (auto iter = children.begin(); iter != children.end(); iter++) {
                delete iter->second;
            }
        }
        std::unordered_map<char, TrieNode*> children;
        bool isEndOfWord;
        int prefixs;
    };

private:
    TrieNode* root_;
};

#endif