#include <stdio.h>

int main()
{
    int d, n, i, j, A[100000], B[100000], cnt, len, newlen;

    scanf("%d %d", &d, &n);

    A[0] = d;
    len = 1;

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < len; j++)
        {
            B[j] = A[j];
        }
        newlen = 0;
        cnt = 1;
        for (j = 0; j < len - 1; j++)
        {
            if (B[j] == B[j + 1])
            {
                cnt++;
            }
            else
            {
                A[newlen++] = B[j];
                A[newlen++] = cnt;
                cnt = 1;
            }
        }
        A[newlen++] = B[j];
        A[newlen++] = cnt;
        len = newlen;
    }

    for (i = 0; i < len; i++)
    {
        printf("%d", A[i]);
    }

    return 0;
}