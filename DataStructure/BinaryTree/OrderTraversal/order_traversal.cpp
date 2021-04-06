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
TreeNode* PreOrderBuild(vector<int>& arr, int i) {
    if (i >= arr.size()) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(arr[i]);
    TreeNode* node = root;
    node->left = PreOrderBuild(arr, 2 * i + 1);
    node->right = PreOrderBuild(arr, 2 * i + 2);
    return root;
}

void PreOrderStack(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    stack<TreeNode*> stack;
    TreeNode* node = root;
    while (!stack.empty() || node != nullptr) {
        while (node != nullptr) {
            cout << node->val << endl;
            stack.push(node);
            node = node->left;
        }
        if (!stack.empty()) {
            node = stack.top();
            stack.pop();
            node = node->right;
        }
    }
}

void PreOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << endl;
    PreOrder(root->left);
    PreOrder(root->right);
}

TreeNode* InOrderBuild(vector<int>& arr, int i) {
    if (i >= arr.size()) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(arr[i]);
    TreeNode* node = root;
    node->left = InOrderBuild(arr, 2 * i + 1);
    node->right = InOrderBuild(arr, 2 * i + 2);
    return root;
}

void InOrderStack(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    stack<TreeNode*> stack;
    while (!stack.empty() || root != nullptr) {
        if (root != nullptr) {
            stack.push(root);
            root = root->left;
        } else {
            root = stack.top();
            stack.pop();
            cout << root->val << endl;
            root = root->right;
        }
    }
}

void InOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    InOrder(root->left);
    cout << root->val << endl;
    InOrder(root->right);
}

void PostOrderStack(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    stack<TreeNode*> stack;
    TreeNode* node = root;
    TreeNode* pre = nullptr;
    while (!stack.empty() || node != nullptr) {
        if (node != nullptr) {
            stack.push(node);
            node = node->left;
        } else {
            node = stack.top();
            if (node->right != nullptr && node->right != pre) {
                node = node->right;
            } else {
                stack.pop();
                cout << node->val << endl;
                pre = node;
                node = nullptr;
            }
        }
    }
}

void PostOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->val << endl;
}

int main() {
    vector<int> arr{1, 2, 3, 4, 5, 6};
    //       1
    //      / \
    //     2   3
    //    / \ / \
    //    4 5 6 7
    TreeNode* root = PreOrderBuild(arr, 0);
    cout << "PreOrder" << endl;
    PreOrder(root);
    cout << "PreOrderStack" << endl;
    PreOrderStack(root);
    cout << "InOrder" << endl;
    InOrder(root);
    cout << "InOrderStack" << endl;
    InOrderStack(root);
    cout << "PostOrder" << endl;
    PostOrder(root);
    cout << "PostOrderStack" << endl;
    PostOrderStack(root);
    return 0;
}