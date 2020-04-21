#include <stdio.h>

int main()
{
    int n, m, i, j, k, A[100][5] = {0}, B[100][8] = {0}, a, b, flag, cnt, max = 0;
    double sum;
    char c;

    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &B[i][0], &B[i][1], &B[i][2]);
        for (j = 0; j < B[i][2]; j++)
        {
            scanf(" %c", &c);
            a = (c - 'a') + 3;
            B[i][a] = 1;
        }
    }

    for (i = 0; i < n; i++)
    {
        sum = 0;
        for (j = 0; j < m; j++)
        {
            flag = 0;
            cnt = 0;
            getchar();
            scanf("(%d", &b);
            for (k = 0; k < b; k++)
            {
                scanf(" %c", &c);
                a = c - 'a';
                if (B[j][a + 3] == 0)
                {
                    flag = 1;
                    A[j][a]++;
                    if (max < A[j][a])
                    {
                        max = A[j][a];
                    }
                }
                else
                {
                    cnt++;
                    B[j][a + 3] = 2;
                }
            }
            scanf(")");
            if (flag == 0)
            {
                if (cnt == B[j][2])
                {
                    sum += B[j][0];
                }
                else
                {
                    sum += B[j][0] * 1.0 / 2;
                }
            }
            for (k = 0; k < B[j][1]; k++)
            {
                if (B[j][k + 3] == 1)
                {
                    A[j][k]++;
                    if (max < A[j][k])
                    {
                        max = A[j][k];
                    }
                }
                else if (B[j][k + 3] == 2)
                {
                    B[j][k + 3] = 1;
                }
            }
        }
        printf("%.1f\n", sum);
    }

    if (max == 0)
    {
        printf("Too simple\n");
    }
    else
    {
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < B[i][1]; j++)
            {
                if (max == A[i][j])
                {
                    printf("%d %d-%c\n", max, i + 1, j + 'a');
                }
            }
        }
    }

    return 0;
}