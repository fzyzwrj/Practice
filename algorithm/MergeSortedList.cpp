// 2016.3.10 by wrj
// src: 《剑指offer》面试题17
// merge two sorted list

struct ListNode
{
    int value;
    ListNode *next;
};

/// still easily ignore some code, which means you don't totally understand.
ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
{
    if (pHead1 == nullptr)
        return pHead2;
    if (pHead2 == nullptr)
        return pHead1;
    ListNode *pMergedHead = nullptr;
    if (pHead1->value < pHead2->value)
    {
        pMergedHead = pHead1;
        pMergedHead->next = Merge(pHead1->next, pHead2);
    }
    else
    {
        pMergedHead = pHead2;
        pMergedHead->next = Merge(pHead1, pHead2->next);
    }
    return pMergedHead;
}

int main()
{
    return 0;
}
