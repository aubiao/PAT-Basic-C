#include <stdio.h>

int main()
{
    int n, m, i, j, k, max = 0, A[1001] = {0}, flag = 0;

    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &k);
            A[j] += k;
            if (max < A[j])
            {
                max = A[j];
            }
        }
    }

    printf("%d\n", max);

    for (i = 0; i < n; i++)
    {
        if (A[i] == max)
        {
            if (flag == 1)
            {
                printf(" ");
            }
            flag = 1;
            printf("%d", i + 1);
        }
    }

    return 0;
}