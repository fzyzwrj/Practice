// 2016.3.9 by wrj
// src: °∂Ω£÷∏offer°∑√Ê ‘Ã‚23
// visit a tree in layer order

#include <iostream>
#include <queue>

struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *lChild, *rChild;
};
void LayerOrder(BinaryTreeNode *pRoot)
{
    if (pRoot == nullptr)
        return;
    std::queue<BinaryTreeNode *>queueTreeNode;
    queueTreeNode.push(pRoot);
    while (queueTreeNode.empty())
    {
        BinaryTreeNode *pNode = queueTreeNode.front();
        queueTreeNode.pop();
        std::cout << pNode->data << std::endl;
        if (pNode->lChild)
            queueTreeNode.push(pNode->lChild);
        if (pNode->rChild)
            queueTreeNode.push(pNode->rChild);
    }

}
int main()
{

    return 0;
}
