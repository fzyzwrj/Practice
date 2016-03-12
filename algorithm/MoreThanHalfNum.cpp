// 2016.3.12 by wrj
// src: Jianzhi Offer, Problem 29
// in O(n) time, find the number which is more than the half of the length of the array
#include <iostream>
/// I made mistakes below, for the number is not continuous.
int MoreThanHalfNum_Wrong(int *a, int length)
{
    int i = 0, j = length - 1;
    int key = a[i];
    while (i < j)
    {
        while (i < j && a[j] >= key)
            --j;
        a[i] = a[j];
        while (i < j && a[i] <= key)
            ++i;
        a[j] = a[i];
    }
    return a[length / 2];
}

int QuickSort(int *a, int low, int high)
{
    if (low >= high)
        return low;
    int i = low, j = high;
    int key = a[i];
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

/// the framework is good.
// The loop is not easily wrote rightly, you can find the k-th nunmber.
int MoreThanHalfNum_QuickSort(int *a, int length)
{
    int low = 0, high = length - 1, middle = length >> 1;

    int index = QuickSort(a, low, high);
    while (index != middle)
    {
        if (index < middle)
            start = index + 1;
        else
            end = index - 1;
        index = QuickSort(a, start, end);
    }
    return a[index];
}

/// The idea is really wit.
bool g_bInputInvalid = false;
void Check(int *a, int length, int res)
{
    int cnt = 0;
    for (int i = 0; i < length; ++i)
        if (a[i] == res)
            ++cnt;
    g_bInputInvalid = cnt > (length >> 1) ? false : true;
}
int MoreThanHalfNum(int *a, int length)
{
    int times = 1;
    int res = a[0];
    for (int i = 1; i < length; ++i)
    {
        if (times == 0)
        {
            res = a[i];
            times = 1;
        }
        else
            res == a[i] ? ++times: --times;
    }
    Check(a, length, res);
    return g_bInputInvalid ? 0 : res;
}


int main()
{
    int a1[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    int a2[] = {1, 2, 3, 2, 2, 2, 5, 2};
    std::cout << MoreThanHalfNum_QuickSort(a1, sizeof(a1) / sizeof(a1[0])) << std::endl;
    std::cout << MoreThanHalfNum_QuickSort(a2, sizeof(a2) / sizeof(a2[0])) << std::endl;
}

