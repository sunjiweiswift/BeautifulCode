#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <unordered_map>
#include <vector>

using namespace std;

template <typename T>
class UnionFind {
public:
    UnionFind() = default;

    ~UnionFind()
    {
        parent_.clear();
        rank_.clear();
    }

    void Union(T a, T b)
    {
        if (parent_.find(a) == parent_.end()) {
            parent_[a] = a;
        }
        if (parent_.find(b) == parent_.end()) {
            parent_[b] = b;
        }
        T aRoot = Find(a);
        T bRoot = Find(b);
        if (aRoot == bRoot) {
            return;
        }
        if (rank_[aRoot] < rank_[bRoot]) {
            parent_[aRoot] = bRoot;
        } else if (rank_[aRoot] > rank_[bRoot]) {
            parent_[bRoot] = aRoot;
        } else {
            parent_[aRoot] = bRoot;
            rank_[bRoot]++;
        }
    }

    T Find(T son)
    {
        if (parent_[son] != son) {
            parent_[son] = Find(son);
        }
        return parent_[son];
    }

    bool isConnected(T a, T b)
    {
        return Find(a) == Find(b);
    }

private:
    unordered_map<T, T> parent_;
    unordered_map<T, int> rank_;
};

#endif