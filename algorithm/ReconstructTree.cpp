// 2016.3.10 by wrj
// src: Jianzhi Offer, problem 6
// reconstruct a tree with preorder and inorder

#include <iostream>
#include <stdexcept>
#include <exception>
struct BinaryTreeNode
{
    int value;
    BinaryTreeNode *lChild, *rChild;
};


BinaryTreeNode *ReconstructCore(int *startPre, int *endPre, int *startIn, int *endIn)
{
    BinaryTreeNode *pRoot = new BinaryTreeNode();
    pRoot->value = startPre[0];
    pRoot->lChild = pRoot->rChild = nullptr;

    // stop recursive
    if (startPre == endPre)
    {
        if (startIn == endIn && *startIn == *startPre)
            return pRoot;
        else
            return nullptr;
            // throw std::exception("Bad input.");
    }

    int *pRootInOrder = startIn;
    while (pRootInOrder <= endIn && *pRootInOrder != pRoot->value)
        ++pRootInOrder;
    if (pRootInOrder == endIn && *pRootInOrder != pRoot->value)
        return nullptr;
        // throw std::exception("Bad input.");

    // understand the below two lines
    int leftLength = pRootInOrder - startPre;
    int *leftPreEnd = startPre + leftLength;

    if (leftLength > 0)
        pRoot->lChild = ReconstructCore(startPre + 1, leftPreEnd, startIn, pRootInOrder - 1);
    if (leftLength < endIn - startIn)
        pRoot->rChild = ReconstructCore(leftPreEnd + 1, endPre, pRootInOrder + 1, endIn);
    return pRoot;
}
BinaryTreeNode *Reconstruct(int *preOrder, int *inOrder, int length)
{
    if (preOrder == nullptr || inOrder == nullptr || length <= 0)
        return nullptr;
    return ReconstructCore(preOrder, preOrder + length - 1, inOrder, inOrder + length - 1);
}



int main()
{
    return 0;
}
