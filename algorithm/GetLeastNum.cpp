// 2016.3.12 by wrj
// Jianzhi Offer, Problem 30
// get the least k numbers of an array

#include <iostream>
#include <set>
#include <vector>
using namespace std;
int AdjustArr(int *a, int low, int high)
{
    if (low >= high)
        return low;
    int i = low, j = high, key = a[i];
    while (i < j)
    {
        while (i < j && a[j] >= key)
            --j;
        a[i] = a[j];
        while (i < j && a[i] <= key)
            ++i;
        a[j] = a[i];
    }
    a[i] = key;
    return i;
}
// Based on quick sort, O(n) while modify the input array.
void GetLeastNum(int *a, int n, int *output, int k)
{
    if (a == nullptr || n <= 0 || output == nullptr || k <= 0)
        return;
    int start = 0, end = n - 1;
    int index = AdjustArr(a, 0, n - 1);
    while (index != k - 1)
    {
        if (index > k - 1)
            end = index - 1;
        else
            end = index + 1;
        index = AdjustArr(a, start, end);
    }
    for (int i = 0; i < k; ++i)
        output[i] = a[i];
}


// Use Rb-tree by multiset in O(nlogk)
void GetLeastNum(const vector<int> &a, multiset<int, greater<int>> &kSet, int k)
{
    kSet.clear();
    if (k <= 0 || a.size() < k)
        return;
    for (auto it = a.cbegin(); it != a.cend(); ++it)
    {
        if (kSet.size() < k)
            kSet.insert(*it);
        else
        {
            if (*kSet.begin() > *it)
            {
                kSet.erase(kSet.begin());
                kSet.insert(*it);
            }
        }
    }
}

int main()
{
    int a[] = {4, 5, 1, 6, 2, 7, 3, 8};
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    const int k = 4;
    int *b = new int[k];
    GetLeastNum(a, sizeof(a) / sizeof(a[0]), b, k);

    for (int i = 0; i < k; ++i)
        std::cout << b[i] << " ";
    std::cout << std::endl;
    delete []b;

    vector<int> v = {4, 5, 1, 6, 2, 7, 3, 8};
    multiset<int, greater<int>> kSet;
    GetLeastNum(v, kSet, k);
    for (auto it = kSet.cbegin(); it != kSet.cend(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}
