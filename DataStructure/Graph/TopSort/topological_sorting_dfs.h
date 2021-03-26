#ifndef TOPOLOGICAL_SORTING_DFS_H
#define TOPOLOGICAL_SORTING_DFS_H

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
        std::vector<T> result;
        std::unordered_map<T, bool> visited;
        for (const T& node : nodes) {
            visited[node] = false;
        }
        std::stack<T> stk;
        for (const T& node : nodes) {
            DFS(node, visited, stk);
        }
        while (!stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }
        return result;
    }

private:
    void DFS(T node, std::unordered_map<T, bool> visited, std::stack<T> result) {
        visited[node] = true;
        for (const T& nextNode = adj_[node]) {
            if (visited[nextNode] == false) {
                DFS(node, visited, result);
            }
        }
        result.push_back(node);
    }

private:
    std::unordered_set<T> nodes_;
    std::unordered_map<T, std::list<T> > adj_;
    std::unordered_map<T, bool> visited_;
};

#endif