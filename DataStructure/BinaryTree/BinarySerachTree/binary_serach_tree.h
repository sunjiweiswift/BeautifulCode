#ifndef _BINARY_SERACH_TREE_H_
#define _BINARY_SERACH_TREE_H_

template <typename Type>
class BSTNode {
public:
    BSTNode(Type key)
        : key(key)
        , left(nullptr)
        , right(nullptr)
        , parent(nullptr)
    {
    }

public:
    Type key;
    BSTNode* left;
    BSTNode* right;
    BSTNode* parent;
};

template <typename Type>
class BinarySerachTree {
public:
    BinarySerachTree();
    ~BinarySerachTree();
    void Inorder(BSTNode<Type>* x);
    BSTNode<Type>* Search(Type key, BSTNode<Type>* node);
    BSTNode<Type>* Search2(Type key, BSTNode<Type>* node);
    BSTNode<Type>* Minimum(BSTNode<Type>* node);
    BSTNode<Type>* Maximum(BSTNode<Type>* node);
    void Insert(BSTNode<Type>* node);

private:
    BSTNode<Type>* Nil;
    BSTNode<Type>* root;

private:
};

#endif