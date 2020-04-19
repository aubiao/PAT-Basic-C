#include <stdio.h>

int main()
{
    int n, A[100000][2] = {0}, i, a, b, m, cnt = 0, flag = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        A[a][0] = b;
        A[b][0] = a;
    }

    scanf("%d", &m);

    for (i = 0; i < m; i++)
    {
        scanf("%d", &a);
        A[a][1] = 1;
        b = A[a][0];
        if (A[b][1] == 1)
        {
            A[a][1] = 2;
            A[b][1] = 2;
            cnt++;
        }
    }

    printf("%d\n", m - cnt * 2);

    for (i = 0; i < 100000; i++)
    {
        if (A[i][1] == 1)
        {
            if (flag == 0)
            {
                flag = 1;
            }
            else
            {
                printf(" ");
            }
            printf("%05d", i);
        }
    }

    return 0;
}