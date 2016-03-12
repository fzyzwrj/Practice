// 2016.3.10 by wrj
// src: Jianzhi Offer, problem 27
// convert a bst to a double linked list without creating any node

/// still not completely understand in the first part.
struct BinaryTreeNode
{
    int value;
    BinaryTreeNode *lChild, *rChild;
};

void Convert(BinaryTreeNode *pRoot, BinaryTreeNode **pLastNodeInList)
{
    if (pRoot == nullptr)
        return;

    // the pRoot is the one going to connect with the double linked list
    BinaryTreeNode *pCur = pRoot;
    if (pCur->lChild)
        Convert(pCur->lChild, pLastNodeInList);
    pCur->lChild = *pLastNodeInList;
    if (*pLastNodeInList)
        (*pLastNodeInList)->rChild = pCur;
    *pLastNodeInList = pCur;
    if (pCur->rChild)
        Convert(pCur->rChild, pLastNodeInList);
}

// my version, using in order traversal, there may be some bug and not precise.
void ConvertWrj(BinaryTreeNode *pRoot, BinaryTreeNode **pLastNodeInList)
{
    if (pRoot == nullptr)
        return;
    // left
    ConvertWrj(pRoot->lChild, pLastNodeInList);

    // current
    if (pRoot->lChild)
        (*pLastNodeInList)->rChild = pRoot;
    pRoot->lChild = &pLastNodeInList;

    // right
    ConvertWrj(pRoot->rChild), pLastNodeInList;
}

BinaryTreeNode *Convert(BinaryTreeNode *pRoot)
{
    BinaryTreeNode *pLastNodeInList = nullptr;      // in the beginning, the pLastNodeInlist is nullptr
    Convert(pRoot, &pLastNodeInList);
    while (pLastNodeInList && pLastNodeInList->lChild)
        pLastNodeInList = pLastNodeInList->lChild;
    return pLastNodeInList;
}

int main()
{
    return 0;
}
