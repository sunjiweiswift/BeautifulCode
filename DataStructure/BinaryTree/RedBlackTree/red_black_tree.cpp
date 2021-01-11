#include "red_black_tree.h"

template <typename Type>
RBTree<Type>::RBTree() {}
template <typename Type>
RBTree<Type>::~RBTree() {}
// template <typename Type>
// bool RBTree<Type>::Insert(const Type& value)
// {
//     RBTreeNode<Type>* pr = Nil;
//     RBTreeNode<Type>* s = root;
//     while (s != Nil) {
//         /* code */
//     }
// }

template <typename Type>
void RBTree<Type>::Insert(RBTreeNode<Type>* z) {
    RBTreeNode<Type>* y = Nil;
    RBTreeNode<Type>* x = root;
    while (x != Nil) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == Nil) {
        root = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
    z->left = Nil;
    z->right = Nil;
    z->color = RED;
    InsertFixUp(z);
}

template <typename Type>
void RBTree<Type>::InsertFixUp(RBTreeNode<Type>* z) {
    while (z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            RBTreeNode<Type>* y = z->parent->parent->right;
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else if (z == z->parent->right) {
                z = z->parent;
                LeftRotate(z);
            }
            z->parent->color = BLACK;
            z->parent->parent = RED;
            RightRotate(z->parent->parent);
        } else {
            RBTreeNode<Type>* y = z->parent->parent->left;
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else if (z == z->parent->left) {
                z = z->parent;
                RightRotate(z);
            }
            z->parent->color = BLACK;
            z->parent->parent = RED;
            LeftRotate(z->parent->parent);
        }
        root->color = BLACK;
    }
}

//   x
//  / \
// xl  y
//    / \
//   yl  yr
template <typename Type>
void RBTree<Type>::LeftRotate(RBTreeNode<Type>* x) {
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

//       x
//      / \
//     y   xr
//    / \
//   yl  yr
template <typename Type>
void RBTree<Type>::RightRotate(RBTreeNode<Type>* x) {
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

template <typename Type>
void RBTree<Type>::Remove(RBTreeNode<Type>* z) {}
int main() {
    return 0;
}
