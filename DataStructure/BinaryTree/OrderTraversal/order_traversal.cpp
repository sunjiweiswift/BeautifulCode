#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};
TreeNode* PreOrderBuild(vector<int>& arr, int i)
{
    if (i >= arr.size()) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(arr[i]);
    TreeNode* node = root;
    node->left = PreOrderBuild(arr, 2 * i + 1);
    node->right = PreOrderBuild(arr, 2 * i + 2);
    return root;
}

void PreOrder(TreeNode* root)
{
    if (root == nullptr) {
        return;
    }
    cout << root->val << endl;
    PreOrder(root->left);
    PreOrder(root->right);
}

TreeNode* InOrderBuild(vector<int>& arr, int i)
{
    if (i >= arr.size()) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(arr[i]);
    TreeNode* node = root;
    node->left = InOrderBuild(arr, 2 * i + 1);
    node->right = InOrderBuild(arr, 2 * i + 2);
    return root;
}

void InOrder(TreeNode* root)
{
    if (root == nullptr) {
        return;
    }
    InOrder(root->left);
    cout << root->val << endl;
    InOrder(root->right);
}

void PostOrder(TreeNode* root)
{
    if (root == nullptr) {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->val << endl;
}

int main()
{
    vector<int> arr { 1, 2, 3, 4, 5, 6 };
    //       1
    //      / \
    //     2   3
    //    / \ / \
    //    4 5 6 7
    TreeNode* root = PreOrderBuild(arr, 0);
    cout << "PreOrder" << endl;
    PreOrder(root);
    cout << "InOrder" << endl;
    InOrder(root);
    cout << "PostOrder" << endl;
    PostOrder(root);
    return 0;
}