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
        head_ = new Cache;
        tail_ = new Cache;
        head_->next = tail_;
        tail_->prev = head_;
    }
    ~LRUCache()
    {
        Cache* cache = head_;
        while (cache != nullptr) {
            Cache* nextCache = cache->next;
            delete cache;
            cache = nextCache;
        }
        delete head_;
        record_.clear();
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
    void PutValue(Key key, Value value)
    {
        auto iter = record_.find(key);
        if (iter != record_.end()) {
            iter->second->value = value;
            MoveToHead(iter->second);
        } else {
            if (capacity_ == record_.size()) {
                Cache* needDel = tail_->prev;
                needDel->prev->next = tail_;
                tail_->prev = needDel;
                record_.erase(needDel->key);
                delete needDel;
            }
            Cache* cache = new Cache(key, value);
            AddCache(cache);
            record_.insert(std::pair<Key, Cache*>(key, cache));
        }
    }

private:
    struct Cache {
        Cache() = default;
        Cache(Key key, Value value)
            : key(key)
            , value(value)
            , prev(nullptr)
            , next(nullptr)
        {
        }
        Key key;
        Value value;
        Cache* prev;
        Cache* next;
    };
    void MoveToHead(Cache* cache)
    {
        if (cache != head_->next) {
            // cache->prev --- cache->next
            cache->prev->next = cache->next;
            cache->next->prev = cache->prev;
            // add cache
            AddCache(cache);
        }
    }
    void AddCache(Cache* cache)
    {
        cache->next = head_->next;
        cache->prev = head_;
        head_->next = cache;
        cache->next->prev = cache;
    }

private:
    Cache* head_;
    Cache* tail_;
    Value error_;
    size_t capacity_;
    std::unordered_map<Key, Cache*> record_;
};

#endif