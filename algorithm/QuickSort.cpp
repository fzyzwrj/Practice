#include <iostream>

/// Practice makes perfect.
void Qsort(int a[], int low, int high)
{
    if (low >= high)
        return;
    int first = low, last = high;
    int key = a[first];

    while (first < last)
    {
        while (first < last && a[last] >= key)
            --last;
        a[first] = a[last];
        while (first < last && a[first] <= key)
            ++first;
        a[last] = a[first];
    }
    a[first] = key;
    Qsort(a, low, first - 1);
    Qsort(a, first + 1, high);
}

void QuickSort(int *a, int low, int high)
{
    if (low >= high)
        return;
    int i = low, j = high;
    int key = a[low];
    while (i < j)
    {
        while (i < j && a[j] >= key)
            --j;
        a[i] = a[j];
        while (i < j && a[i] <= key)
            ++i;
        a[j] = a[i];
    }
    a[i] = key; // after the loop, i and j in the same position
    QuickSort(a, low, i - 1);
    QuickSort(a, i + 1, high);
}


int main()
{
    int a[] = {57, 68, 59, 52, 72, 28, 96, 33, 24};
    int num = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < num; ++i)
    std::cout << a[i] << " ";
    std::cout << std::endl;

//    Qsort(a, 0, num - 1);
    QuickSort(a, 0, num - 1);
    for (int i = 0; i < num; ++i)
        std::cout << a[i] << " ";
    std::cout << std::endl;
    return 0;
}
