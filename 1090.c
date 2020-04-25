#include <stdio.h>

int A[100000][100] = {0}, B[100000] = {0}, C[1000];

int main()
{
    int n, m, i, j, k, a, b, flag;

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        A[a][0]++;
        A[a][A[a][0]] = b;
        A[b][0]++;
        A[b][A[b][0]] = a;
    }

    for (i = 0; i < m; i++)
    {
        scanf("%d", &b);
        flag = 0;
        for (j = 0; j < b; j++)
        {
            scanf("%d", &a);
            B[a] = 1;
            C[j] = a;
        }
        for (j = 0; j < b; j++)
        {
            for (k = 1; k <= A[C[j]][0]; k++)
            {
                if (B[A[C[j]][k]] == 1)
                {
                    printf("No\n");
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                break;
            }
        }
        if (flag == 0)
        {
            printf("Yes\n");
        }
        for (j = 0; j < b; j++)
        {
            B[C[j]] = 0;
        }
    }

    return 0;
}