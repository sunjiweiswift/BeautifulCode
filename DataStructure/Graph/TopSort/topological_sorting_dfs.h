#ifndef TOPOLOGICAL_SORTING_DFS_H
#define TOPOLOGICAL_SORTING_DFS_H
#include <algorithm>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template <typename T>
class GraphDFS {
public:
    void AddEdge(T a, T b) {
        adj_[a].push_back(b);
        nodes_.insert(a);
        nodes_.insert(b);
    }

    std::vector<T> TopologicalSorting() {
        for (const T& node : nodes_) {
            visited_[node] = false;
        }
        for (const T& node : nodes_) {
            if (visited_[node] == false) {
                DFS(node);
            }
        }
        std::vector<T> result = postOrder_;
        std::reverse(result.begin(), result.end());
        return result;
    }

private:
    void DFS(T node) {
        visited_[node] = true;
        for (const T& nextNode : adj_[node]) {
            if (visited_[nextNode] == false) {
                DFS(nextNode);
            }
        }
        postOrder_.push_back(node);
    }

private:
    std::unordered_set<T> nodes_;
    std::unordered_map<T, std::list<T>> adj_;
    std::unordered_map<T, bool> visited_;
    std::vector<T> postOrder_;
};

#endif