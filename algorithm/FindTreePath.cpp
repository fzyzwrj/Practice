// 2016.3.10 by wrj
// src: Jianzhi Offer, problem 25
// print all the path from the root to the leaf node, of which sum equals the given number

#include <iostream>
#include <vector>

struct BinaryTreeNode
{
    int value;
    BinaryTreeNode *lChild, *rChild;
};


/// the code is extremely concise and easily understood, but you didn't write it down before.
void FindPath(BinaryTreeNode *pNode, int expectedSum, std::vector<int> &path, int currentSum)
{
    currentSum += pNode->value;
    path.push_back(pNode->value);
    if (pNode->lChild == nullptr && pNode->rChild == nullptr && currentSum == expectedSum)
    {
        for (auto it = path.cbegin(); it != path.cend(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
    }
    if (pNode->lChild)
        FindPath(pNode->lChild, expectedSum, path, currentSum);
    if (pNode->rChild)
        FindPath(pNode->rChild, expectedSum, path, currentSum);
    path.pop_back();
}
void FindPath(BinaryTreeNode *pRoot, int expectedSum)
{
    if (pRoot == nullptr)
        return;
    std::vector<int> path;
    int currentSum = 0;
    FindPath(pRoot, expectedSum, path, currentSum);
}

int main()
{
    return 0;
}
