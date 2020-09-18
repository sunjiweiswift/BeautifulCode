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
    }
    s void PutValue(Key key, Value value)
    {
        auto iter = record_.find(key);
        if (iter != record_.end()) {
            iter->second->value = value;
            MoveToHead(iter->second);
        } else {
            if (capacity_ == record_.size()) {
                // Delete tail->prev node
                CacheNode* needDel = tail_->prev;
                needDel->prev->next = needDel->next;
                needDel->next->prev = needDel->prev;
                record_.erase(needDel->key);
                delete needDel;
            }
            CacheNode* cache = new CacheNode(key, value);
            AddCache(cache);
            record_.insert(std::pair<Key, CacheNode*>(key, cache));
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
    size_t minFreq_;
    // std::unordered_map<Key, List<int>> > countSort_;
    std::unordered_map<Key, CacheNode > countSort_;
};

#endif