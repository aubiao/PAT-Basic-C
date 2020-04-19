#include <stdio.h>

int main()
{
    int n, m, A[100][2], i, j, k, sum;

    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++)
    {
        scanf("%d", &A[i][0]);
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d", &A[i][1]);
    }

    for (i = 0; i < n; i++)
    {
        sum = 0;
        for (j = 0; j < m; j++)
        {
            scanf("%d", &k);
            if (k == A[j][1])
            {
                sum += A[j][0];
            }
        }
        printf("%d\n", sum);
    }

    return 0;
}