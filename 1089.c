#include <stdio.h>

int main()
{
    int n, i, j, cnt, cnta, cntb, flag, k, A[101] = {0}, B[3];

    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &A[i]);
    }

    for (i = 1; i < n; i++)
    {
        for (j = i + 1; j <= n; j++)
        {
            cnt = 0;
            cnta = 0;
            cntb = 0;
            for (k = 1; k <= n; k++)
            {
                flag = 0;
                if (A[k] < 0 && -A[k] != i && -A[k] != j)
                {
                    cnt++;
                    flag = 1;
                }
                else if (A[k] > 0 && (A[k] == i || A[k] == j))
                {
                    cnt++;
                    flag = 1;
                }
                if (flag == 1)
                {
                    if (k == i || k == j)
                    {
                        cnta++;
                    }
                    else
                    {
                        cntb++;
                    }
                }
                if (cnt > 2)
                {
                    break;
                }
                if (cnta > 1)
                {
                    break;
                }
                if (cntb > 1)
                {
                    break;
                }
            }
            if (cnt == 2 && cnta == 1 && cntb == 1)
            {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }

    if (cnt != 2 || cnta != 1 || cntb != 1)
    {
        printf("No Solution\n");
    }

    return 0;
}