#ifndef HASHMAP_H
#define HASHMAP_H

template <class Key, class Value>
class HashNode {
public:
    Key key_;
    Value value_;
    HashNode* next_;

    HashNode(Key key, Value value) {
        key_ = key;
        value_ = value;
        next_ = nullptr;
    }
    ~HashNode() {}
    HashNode& operator=(const HashNode& node) {
        key_ = node.key_;
        value_ = node.value_;
        next_ = node.next_;
        return *this;
    }
};

template <class Key, class Value, class HashFunc, class EqualKey>
class HashMap {
public:
    HashMap(int size) : size_(size), hash(), equal() {
        table_ = new HashNode<Key, Value>*[size_];
        for (size_t i = 0; i < size_; i++) {
            table_[i] = nullptr;
        }
    }

    ~HashMap() {
        for (size_t i = 0; i < size_; i++) {
            HashNode<Key, Value>* currentNode = table_[i];
            while (currentNode) {
                HashNode<Key, Value>* temp = currentNode;
                currentNode = currentNode->next_;
                delete temp;
            }
        }
        delete[] table_;
    }

    bool put(const Key& key, const Value& value) {
        int index = hash(key) % size_;
        HashNode<Key, Value>* node = table_[index];
        while (node) {
            if (node->key == key) {
                node->value = value;
                return true;
            }
            node = node->next;
        }
        node = new HashNode<Key, Value>(key, value);
        node->next_ = table_[index];
        table_[index] = node;
        return false;
    }

    bool insert(const Key& key, const Value& value) {
        int index = hash(key) % size_;
        HashNode<Key, Value>* node = new HashNode<Key, Value>(key, value);
        node->next_ = table_[index];
        table_[index] = node;
        return true;
    }

    bool del(const Key& key) {
        unsigned index = hash(key) % size_;
        HashNode<Key, Value>* node = table_[index];
        HashNode<Key, Value>* prev = nullptr;
        while (node) {
            if (node->key_ == key) {
                if (prev == nullptr) {
                    table_[index] = node->next_;
                } else {
                    prev->next_ = node->next_;
                }
                delete node;
                return true;
            }
            prev = node;
            node = node->next_;
        }
        return false;
    }

    Value& find(const Key& key) {
        unsigned index = hash(key) % size_;
        if (table_[index] != nullptr) {
            HashNode<Key, Value>* node = table_[index];
            while (node) {
                if (node->key_ == key) {
                    return node->value_;
                }
                node = node->next_;
            }
        }
        return Valuenullptr;
    }

    Value& operator[](const Key& key) { return find(key); }

private:
    HashFunc hash;
    EqualKey equal;
    HashNode<Key, Value>** table_;
    unsigned int size_;
    Value Valuenullptr;
};

#endif