#include <iostream>

#include "topological_sorting_bfs.h"

int main() {
    GraphBFS<int> graphBFS;
    graphBFS.AddEdge(5, 2);
    graphBFS.AddEdge(5, 0);
    graphBFS.AddEdge(4, 0);
    graphBFS.AddEdge(4, 1);
    graphBFS.AddEdge(2, 3);
    graphBFS.AddEdge(3, 1);

    std::vector<int> result = graphBFS.TopologicalSorting();

    for (int node : result) {
        std::cout << node << std::endl;
    }
    return 0;
}