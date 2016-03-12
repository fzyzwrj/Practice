// 2016.3.11 by wrj
// src: Jianzhi Offer, problem 28
// print all the permutation of a string
#include <iostream>
#include <cstdio>

template<typename T>
void swap(T &a, T &b)
{
    T t = a;
    a = b;
    b = t;
}

// all elem should be swap with itself. For example, "abc" is swapped three times.
void Permutation(char *pStr, char *pBegin)
{
    static int cnt = 0;
    if (pBegin == '\0')
    {
        cnt++;
        printf("%4d: %s\n", cnt, pStr);
    }
    else
    {
        for (char *pCh = pBegin; *pCh != '\0'; ++pCh)
        {
            swap(*pCh, *pBegin);
            Permutation(pStr, pBegin + 1);
            swap(*pCh, *pBegin);
        }
    }

}

void Permutation(char *str)
{
    if (str == nullptr)
        return;
    Permutation(str, str);
}

int main()
{
    char str[] = "abcd";
    Permutation(str);
    return 0;
}
