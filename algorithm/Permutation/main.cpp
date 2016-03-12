// 2016.3.11 by wrj
// src: Jianzhi Offer, problem 28
// print all the permutation of a string
// see more similar problem in http://blog.csdn.net/hackbuteer1/article/details/7462447

/*
 * You should rewrite and rethink the code for many times.
 * This problem is equal to 8 queens.
 * abc's permutation is equal to below:
 * a + permutation(bc)
 * b + permutation(ac)
 * c + permutation(ab)
 * So you find the recursion could realize multiplication principle(Ann is a special case),
 * while the for loop could realize addition principle
 */
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
    if (*pBegin == '\0')        /// I miss the '*' here, then debug for a long time!!!
    {
        cnt++;
        printf("%4d: %s\n", cnt, pStr);
    }
    else
    {
        for (char *pCh = pBegin; *pCh != '\0'; ++pCh)
        {
            swap(*pCh, *pBegin);
            Permutation(pStr, pBegin + 1);      /// the most important line
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
