// 2016.3.10 by wrj
// src: 《剑指offer》面试题18
// judge whether a tree is a subtree of another

struct BinaryTreeNode
{
    int value;
    BinaryTreeNode *lChild, *rChild;
};


/// still be very unfamiliar with the problem, easily wrong
/// why split into 2 funcs?
bool JudgeSubTree(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2)
{
    if (pRoot2 == nullptr)
        return true;
    if (pRoot1 == nullptr)
        return false;
    if (pRoot1->value =! pRoot2->value)
        return false;
    return JudgeSubTree(pRoot1->lChild, pRoot2->lChild) && JudgeSubTree(pRoot1->rChild, pRoot2->rChild);
}
bool HasSubTree(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2)
{
    bool res = false;
    if (pRoot1 && pRoot2)
    {
        if (pRoot1->value == pRoot2->value)
            res = JudgeSubTree(pRoot1, pRoot2);
        if (!res)
            res = HasSubTree(pRoot1->lChild, pRoot2);
        if (!res)
            res = HasSubTree(pRoot1->rChild, pRoot2);
    }
    return res;
}


int main()
{
    return 0;
}
