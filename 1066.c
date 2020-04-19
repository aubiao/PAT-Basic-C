#include <stdio.h>

int main()
{
    int m, n, a, b, i, j, c, d;

    scanf("%d %d %d %d %d", &m, &n, &a, &b, &c);

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &d);
            if (d >= a && d <= b)
            {
                d = c;
            }
            printf("%03d", d);
            if (j != n - 1)
            {
                printf(" ");
            }
            else
            {
                printf("\n");
            }
        }
    }

    return 0;
}