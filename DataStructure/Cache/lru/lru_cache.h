#ifndef LRU_CACHE_H
#define LRU_CACHE_H
#include <unordered_map>

template <typename Key, typename Value>
class LRUCache {
public:
    LRUCache(size_t capacity, Value error)
        : capacity_(capacity)
        , error_(error)
    {
        head_ = new CacheNode();
        tail_ = new CacheNode();
        head_->next = tail_;
        tail_->prev = head_;
    }

    Value GetValue(Key key)
    {
        auto iter = record_.find(key);
        if (iter == record_.end()) {
            return error_;
        } else {
            MoveToHead(iter->second);
            return iter->second->value;
        }
    }s
    void PutValue(Key key, Value value)
    {
        auto iter = record_.find(key);
        if (iter != record_.end()) {
            iter->second->value = value;
            MoveToHead(iter->second);
        } else {
            if (capacity_ == record_.size()) {
                // Delete tail->prev node
                CacheNode* needRemove = tail_->prev;
                needRemove->prev->next = needRemove->next;
                needRemove->next->prev = needRemove->prev;
                record_.erase(needRemove->key);
                delete needRemove;
            }
            CacheNode* cache = new CacheNode(key, value);
            AddCache(cache);
            record_.insert(std::pair<Key, CacheNode*>(key, cache));
        }
    }

private:
    struct CacheNode {
        CacheNode() = default;
        CacheNode(Key key, Value value)
            : key(key)
            , value(value)
            , prev(nullptr)
            , next(nullptr)
        {
        }
        Key key;
        Value value;
        CacheNode* prev;
        CacheNode* next;
    };
    void MoveToHead(CacheNode* cache)
    {
        if (cache != head_->next) {
            // cache->prev --- cache->next
            cache->prev->next = cache->next;
            cache->next->prev = cache->prev;
            // add cache
            AddCache(cache);
        }
    }
    void AddCache(CacheNode* cache)
    {
        cache->next = head_->next;
        cache->prev = head_;
        head_->next = cache;
        cache->next->prev = cache;
    }

private:
    CacheNode* head_;
    CacheNode* tail_;
    Value error_;
    size_t capacity_;
    std::unordered_map<Key, CacheNode*> record_;
};

#endif