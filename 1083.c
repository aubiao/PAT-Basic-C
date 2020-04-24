#include <stdio.h>

int main()
{
    int n, A[10000] = {0}, i, a, max = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if (a > i + 1)
        {
            a -= i + 1;
        }
        else
        {
            a = i + 1 - a;
        }
        if (max < a)
        {
            max = a;
        }
        A[a]++;
    }

    for (i = max; i >= 0; i--)
    {
        if (A[i] > 1)
        {
            printf("%d %d\n", i, A[i]);
        }
    }

    return 0;
}