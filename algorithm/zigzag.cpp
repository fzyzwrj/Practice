// 2016.3.2 wrj
// print array in zigzag
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
  int n;
    cin >> n;
    int **a = (int **)malloc(sizeof(int *) * n);
    if (a == NULL)
        return 0;
    for (int i = 0; i < n; ++i)
    {
        a[i] = (int *)malloc(sizeof(int) * n);
        if (a[i] == NULL)
        {
            while (i--)
                free(a[i]);
            free(a);
        }
    }

    int squa = n * n - 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int s = i + j;
            if (s < n)
                a[i][j] = s * (s + 1) / 2 + (s % 2 == 0 ? i : j);
            else
            {
                int ii = n - i - 1;
                int jj = n - j - 1;
                s = ii + jj;
                a[i][j] = squa - (s * (s + 1) /2 + (s % 2 == 0 ? ii : jj)); // 两者是对称的
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            printf("%4d", a[i][j]);
        printf("\n");
    }
    for (int i= 0; i < n; ++i)
        free(a[i]);
    free(a);
    return 0;
}
