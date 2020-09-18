#ifndef LRU_CACHE_H
#define LRU_CACHE_H
#include <list>
#include <unordered_map>

template <typename Key, typename Value>
class LFUCache {
public:
    LFUCache(size_t capacity, Value error)
        : capacity_(capacity)
        , error_(error)
        , size_(0)
        , minFreq_(0)
    {
    }

    Value GetValue(Key key)
    {
        auto iter = recordCache_.find(key);
        if (iter == recordCache_.end()) {
            return error_;
        }
        UpdateFreq(iter->second);
        return iter->second->value;
    }
    void PutValue(Key key, Value value)
    {
        if (capacity_ == 0) {
            return;
        }
        auto iter = recordCache_.find(key);
        if (iter != recordCache_.end()) {
            iter->second->value = value;
            UpdateFreq(iter->second);
        } else {
            if (size_ == capacity_) {
                // Remove
                DoublyLinkedList* minFreqList = recordFreq_[minFreq_];
                CacheNode* needRemove = minFreqList->GetBack();
                minFreqList->RemoveNode(needRemove);
                recordCache_.erase(needRemove->key);
                // delete needRemove;
                size_--;
            }
            CacheNode* newNode = new CacheNode(key, value);
            recordCache_.insert(std::pair<Key, CacheNode*>(key, newNode));
            auto iter = recordFreq_.find(1);
            if (iter == recordFreq_.end()) {
                DoublyLinkedList* list = new DoublyLinkedList();
                recordFreq_.insert(std::pair<size_t, DoublyLinkedList*>(1, list));
            }
            recordFreq_[1]->AddNode(newNode);
            size_++;
            minFreq_ = 1;
        }
    }

private:
    struct CacheNode {
        CacheNode() = default;
        CacheNode(Key key, Value value, size_t freq)
            : key(key)
            , value(value)
            , freq(freq)
            , prev(nullptr)
            , next(nullptr)
        {
        }
        Key key;
        Value value;
        size_t freq;
        CacheNode* prev;
        CacheNode* next;
    };
    class DoublyLinkedList {
    public:
        DoublyLinkedList()
        {
            head_ = new CacheNode();
            tail_ = new CacheNode();
            head_->next = tail_;
            tail_->prev = head_;
        }
        ~DoublyLinkedList()
        {
            delete head_;
            delete tail_;
        }
        void RemoveNode(CacheNode* node)
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        void AddNodeFront(CacheNode* node)
        {
            node->next = head_->next;
            node->prev = head_;
            head_->next->prev = node;
            head_->next = node;
        }
        CacheNode* GetBack()
        {
            return Empty() ? nullptr : tail_->prev;
        }
        bool Empty()
        {
            return head_->next == tail_;
        }

    private:
        CacheNode* head_;
        CacheNode* tail_;
    };
    void UpdateFreq(CacheNode* node)
    {
        // size_t freq = node->freq;
        auto iter = recordFreq_.find(node->freq);
        iter->second->RemoveNode(node);
        if (node->freq == minFreq_ && iter->second->Empty()) {
            minFreq_++;
        }
        node->freq++;
        iter = recordFreq_.find(node->freq);
        if (iter == recordFreq_.end()) {
            DoublyLinkedList* list = new DoublyLinkedList();
            recordFreq_.insert(std::pair<size_t, DoublyLinkedList*>(node->freq, list));
        }
        iter->second->AddNodeFront(node);
    }

private:
    Value error_;
    size_t capacity_;
    size_t size_;
    size_t minFreq_;
    std::unordered_map<Key, CacheNode> recordCache_;
    std::unordered_map<size_t, DoublyLinkedList*> recordFreq_;
};

#endif