#include <stdio.h>

int main()
{
    int n, m, scnt = 0, a, k, cnt = 0, flag, i, j, A[10000] = {0};
    char name[5];

    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++)
    {
        scanf("%d", &a);
        A[a] = 1;
    }

    for (i = 0; i < n; i++)
    {
        flag = 0;
        scanf("%s %d", name, &k);
        for (j = 0; j < k; j++)
        {
            scanf("%d", &a);
            if (A[a] == 1)
            {
                if (flag == 0)
                {
                    printf("%s:", name);
                    flag = 1;
                }
                printf(" %04d", a);
                cnt++;
            }
        }
        if (flag == 1)
        {
            scnt++;
            printf("\n");
        }
    }

    printf("%d %d\n", scnt, cnt);

    return 0;
}