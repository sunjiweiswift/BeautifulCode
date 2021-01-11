#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

vector<int> TopSort(vector<pair<int, int>>& graph, vector<int>& nodes) {
    queue<int> queue;
    map<int, int> indegrees;
    map<int, set<int>> outNodes;
    vector<int> ans;
    for (pair<int, int> iter : graph) {
        indegrees[iter.second]++;
        outNodes[iter.first].insert(iter.second);
    }
    // indegree equal zero push to queue
    for (int node : nodes) {
        if (indegrees[node] == 0) {
            queue.push(node);
        }
    }
    while (!queue.empty()) {
        int inNode = queue.front();
        queue.pop();
        ans.push_back(inNode);
        for (int outNode : outNodes[inNode]) {
            indegrees[outNode]--;
            if (indegrees[outNode] == 0) {
                queue.push(outNode);
            }
        }
    }
    return ans;
}
int main() {
    // 2---->3---->5
    // ^ |         ^
    // |   |       |
    // |     |     |
    // |       |-->|
    // 1---------->4
    vector<pair<int, int>> graph{pair<int, int>(1, 4), pair<int, int>(1, 2), pair<int, int>(2, 3),
                                 pair<int, int>(2, 4), pair<int, int>(3, 5), pair<int, int>(4, 5)};
    vector<int> nodes{1, 2, 3, 4, 5};
    vector<int> ans = TopSort(graph, nodes);
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}