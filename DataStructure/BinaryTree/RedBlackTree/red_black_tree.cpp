#include <iostream>

using namespace std;

template <typename Type>
struct RBTreeNode {
    enum {
        RED = 0,
        BLACK
    } color;
    Type key;
    RBTreeNode* left;
    RBTreeNode* right;
    RBTreeNode* parent;
};

template <typename Type>
class RBTree {
public:
    RBTree();
    ~RBTree();
    bool Insert(const Type& value)
    {
        RBTreeNode<Type>* pr = Nil;
        RBTreeNode<Type>* s = root;
        while (s != Nil) {
            /* code */
        }
    }
    void Romove(Type key) { }

protected:
    void LeftRotate(RBTreeNode<Type>* x)
    {
        RBTreeNode<Type>* y = x->right;
        x->right = y->left;
        if (y->left != Nil) {
            y->left->parent = x;
        }
        // Modify y parent
        y->parent = x->parent;
        // Modify Paraent lefr or right
        if (x == root) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->right = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }
    void RightRotate(RBTreeNode<Type>* x)
    {
        RBTreeNode<Type>* y = x->left;
        x->left = y->right;
        if (y->right != Nil) {
            y->right->parent = x;
        }
        // Modify y parent
        y->parent = x->parent;
        // Modify Paraent lefr or right
        if (x == root) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->right = y;
        } else {
            x->parent->right = y;
        }
        y->right = x;
        x->parent = y;
    }

private:
    RBTreeNode<Type>* root; // root node
    RBTreeNode<Type>* Nil; // Exetern node
};

int main()
{
    return 0;
}
