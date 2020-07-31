#ifndef _RED_BLACK_H_
#define _RED_BLACK_H_
typedef enum {
    RED = 0,
    BLACK
} Color;
template <typename Type>
struct RBTreeNode {
    Color color;
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

protected:
    void Insert(RBTreeNode<Type>* z);
    void InsertFixUp(RBTreeNode<Type>* z);
    void Remove(RBTreeNode<Type>* z);
    void LeftRotate(RBTreeNode<Type>* x);
    void RightRotate(RBTreeNode<Type>* x);

private:
    RBTreeNode<Type>* root; // root node
    RBTreeNode<Type>* Nil; // Exetern node
};
#endif