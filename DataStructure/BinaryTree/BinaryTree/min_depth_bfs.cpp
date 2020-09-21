#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int MinDepth(TreeNode* root)
{
    if (root == nullptr) {
        return 0;
    }
    queue<pair<TreeNode*, int>> que;
    que.emplace(root, 1);
    while (!que.empty()) {
        TreeNode* node = que.front().first;
        int depth = que.front().second;
        que.pop();
        if (node->left == nullptr && node->right == nullptr) {
            return depth;
        }
        if (node->left != nullptr) {
            que.emplace(node->left, depth + 1);
        }
        if (node->right != nullptr) {
            que.emplace(node->right, depth + 1);
        }
    }
    return 0;
}

int main()
{
//        3
//       / \
//      1   4
//     / \
//    0   2
    TreeNode* head = new TreeNode(3);
    head->left = new TreeNode(1);
    head->right = new TreeNode(4);
    head->left->left = new TreeNode(0);
    head->left->right = new TreeNode(2);
    cout << MinDepth(head) << endl;
    return 0;
}