#include <iostream>

#include "topological_sorting_bfs.h"
#include "topological_sorting_dfs.h"

int main() {
    GraphBFS<int> graphBFS;
    graphBFS.AddEdge(5, 2);
    graphBFS.AddEdge(5, 0);
    graphBFS.AddEdge(4, 0);
    graphBFS.AddEdge(4, 1);
    graphBFS.AddEdge(2, 3);
    graphBFS.AddEdge(3, 1);

    std::cout << "TopSortBFS" << std::endl;
    for (int node : graphBFS.TopologicalSorting()) {
        std::cout << node << std::endl;
    }

    GraphDFS<int> graphDFS;
    graphDFS.AddEdge(5, 2);
    graphDFS.AddEdge(5, 0);
    graphDFS.AddEdge(4, 0);
    graphDFS.AddEdge(4, 1);
    graphDFS.AddEdge(2, 3);
    graphDFS.AddEdge(3, 1);

    std::cout << "TopSortDFS" << std::endl;
    for (int node : graphDFS.TopologicalSorting()) {
        std::cout << node << std::endl;
    }
    return 0;
}