#ifndef TOPOLOGICAL_SORTING_BFS_H
#define TOPOLOGICAL_SORTING_BFS_H

#include <list>
#include <queue>
#include <unordered_map>

template <typename T>
class GraphBFS {
public:
    GraphBFS(int nodeNums) : nodeNums(nodeNums) {}
    ~GraphBFS();
    void AddEdge(T a, T b) {
        adj_[a].push_back(b);
        ++indegree[b];
    }
    bool TopologicalSorting() {
        
    }
public:
    int nodeNums_;
    std::unordered_map<T, list<T>> adj_;
    std::queue<T> que_;
    std::unordered_map<T, int> indegree;
};

#endif