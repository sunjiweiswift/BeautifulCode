#include <iostream>
#include <vector>
using namespace std;

void Dijkstra(vector<vector<int>>& cost, vector<int>& result, int v0) {
    vector<int> visited(cost.size(), 0); // 表示顶点是否被选中，0：顶点未被选中；1：顶点已被选中
    int last_visited = 0;
    visited[v0] = 1; // 选中起始顶点
    result[0] = 0;

    for (int i = 0; i < cost.size() - 1; ++i) { // N 个顶点需要做 N - 1 次循环
        // 查看顶点周围的所有点
        for (int j = 0; j < cost.size(); ++j) { // 循环遍历所有顶点
            if (visited[j] == 0) {             // 保证被查看的新顶点没有被访问到
                if (cost[v0][j] != 0) { // 保证当前顶点（V0）与新顶点（j）之间有路径
                    int dist = cost[v0][j] + last_visited;   // 计算 V0 到 J 的路径距离
                    if (dist < result[j]) result[j] = dist; // 用新路径代替原来的路径
                }
            }
        }
        // 找出最小值
        int minIndex = 0;
        while (visited[minIndex] == 1) minIndex++; // 找第一个没有被选中的节点
        for (int j = minIndex; j < cost.size(); ++j) {
            if (visited[j] == 0 && result[j] < result[minIndex]) {
                minIndex = j;
            }
        }

        last_visited = result[minIndex]; // 更新最小值
        visited[minIndex] = 1;           // 将最小值顶点选中
        v0 = minIndex;                   // 下次查找从最限制顶点开始
    }
}
int main() {
    return 0;
}