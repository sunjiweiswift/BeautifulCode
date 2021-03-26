#ifndef TOPOLOGICAL_SORTING_DFS_H
#define TOPOLOGICAL_SORTING_DFS_H

#include <list>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template <typename T>
class GrapgDFS {
public:
    GrapgDFS() = default;
    ~GrapgDFS() = default;
    void AddEdge(T a, T b) {
        adj_[a].push_back(b);
        ++indegree_[b];
        nodes_.insert(a);
        nodes_.insert(b);
    }
    std::vector<T> TopologicalSorting() {
        std::vector<T> result;
        std::queue<T> que;
        for (auto node : nodes_) {
            if (indegree_[node] == 0) {
                que.push(node);
            }
        }
        while (!que.empty()) {
            T node = que.front();
            que.pop();
            result.push_back(node);
            for (auto iter : adj_[node]) {
                if (--indegree_[iter] == 0) {
                    que.push(iter);
                }
            }
        }
        return result;
    }

public:
    std::unordered_set<T> nodes_;
    std::unordered_map<T, std::list<T> > adj_;
    std::unordered_map<T, int> indegree_;
};

#endif