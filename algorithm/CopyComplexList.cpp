// 2016.3.10 by wrj
// src: Jianzhi Offer, problem 26
// copy a complex list in O(n), this is a good problem.


/// I didn't test my code.
struct ComplexListNode
{
    int value;
    ComplexListNode *next;
    ComplexListNode *sibling;
};

void CloneNodes(ComplexListNode *pHead)
{
    ComplexListNode *p = pHead;
    while (p)
    {
        ComplexListNode *pCloneListNode = new ComplexListNode();
        pCloneListNode->value = p->value;
        pCloneListNode->next = p->next;
        pCloneListNode->sibling = nullptr;
        p->next = pCloneListNode;
        p = pCloneListNode->next;
    }
}


void ConnectSiblingNodes(ComplexListNode *pHead)
{
    ComplexListNode *p = pHead;
    while (p)
    {
        p->next->sibling = (p->sibling ? p->sibling->next : nullptr);
        p = p->next->next;
    }
}

ComplexListNode *ReconnectNodes(ComplexListNode *pHead)
{
    if (pHead == nullptr)
        return nullptr;
    ComplexListNode *pCloneHead = pHead->next;
    ComplexListNode *pNode = pHead;
    ComplexListNode *pCloneNode = pCloneHead;
    while (pNode)
    {
        // here different from the book, what I wrote down is not concise
        if (pCloneNode->next)
        {
            pNode->next = pCloneNode->next;
            pNode = pNode->next;
            pCloneNode->next = pNode->next;
            pCloneNode = pCloneNode->next;
        }
        else
        {
            pNode->next = pCloneNode->next = nullptr;
            pNode = nullptr;
        }
    }
}

ComplexListNode *Clone(ComplexListNode *pHead)
{
    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
    return ReconnectNodes(pHead);
}


int main()
{
    return 0;
}
