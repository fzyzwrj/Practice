// 2016.3.10 by wrj
// src: Jianzhi Offer, Problem 24
// verify whether a sequence is a post traversal of a BST
// hint: in a bst, left elem is smaller, right elem is larger, and the last elem is the root.
#include <iostream>

/// the first time, I thought wrong.
bool VerifySeqOfBST(int *seq, int length)
{
//    if (seq == nullptr || length <= 0)
//        return false;
//    if (length == 1)
//        return true;
//    int *rightStart = seq;
//    while (rightStart < seq + length && *rightStart <= seq[length - 1])
//        ++rightStart;
//
//    if (rightStart)
//    int leftLength = rightStart - seq;
//    bool left = true;
//    if (leftLength > 0)
//        left = VerifySeqOfBST(seq, rightStart - seq);
//    bool right = true;
//    int rightLength = length - leftLength - 1;
//    if (length - leftLength > 0)
//        right = VerifySeqOfBST(rightStart, rightLength);
//    return left && right;
    if (seq == nullptr || length <= 0)
        return false;
    int root = seq[length - 1];

    // all nodes less than root value.
    int i = 0;
    for (; i < length - 1; ++i)
        if (seq[i] > root)
            break;

    // verify the others nodes is greater than root value, else reutrn false.
    int j = i;
    for (; j < length - 1; ++j)
        if (seq[j] < root)
            return false;

    // if left child is not null, verify left child.
    bool left = true;
    if (i > 0)
        left = VerifySeqOfBST(seq, i);
    // if right child is not null, verify right child.
    bool right = true;
    if (i < length - 1) // i is the start, length - 1 is the end, there should be some elem between them.
        right = VerifySeqOfBST(seq + i, length - i - 1);

    return left && right;
}


int main()
{
    int arr1[7] = {5, 7, 6, 9, 11, 10, 8};
    std::cout << VerifySeqOfBST(arr1, 7) << std::endl;
    int arr2[4] = {7, 4, 6, 5};
    std::cout << VerifySeqOfBST(arr2, 4) << std::endl;
    return 0;
}
