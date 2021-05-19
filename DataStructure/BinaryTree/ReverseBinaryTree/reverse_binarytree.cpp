#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void ReverseNode(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    TreeNode* left = node->left;
    TreeNode* right = node->right;
    node->right = left;
    node->left = right;
    ReverseNode(node->left);
    ReverseNode(node->right);
}

void ReverseNodeStack(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    stack<TreeNode*> stk;
    stk.push(node);
    while (!stk.empty()) {
        node = stk.top();
        stk.pop();
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        node->left = right;
        node->right = left;
        if (left != nullptr) {
            stk.push(left);
        }
        if (right != nullptr) {
            stk.push(right);
        }
    }
}

void PrintBinaryTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    PrintBinaryTree(root->left);
    PrintBinaryTree(root->right);
}
int main() {
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
    cout << "before reverse" << endl;
    PrintBinaryTree(head);
    cout << endl;
    // first reverse
    cout << "first reverse" << endl;
    ReverseNode(head);
    PrintBinaryTree(head);
    cout << endl;
    // second reverse
    cout << "second reverse" << endl;
    ReverseNodeStack(head);
    PrintBinaryTree(head);
    cout << endl;
    return 0;
}
