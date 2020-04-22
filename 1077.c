#include <stdio.h>

int main()
{
    int n, m, i, j, min, max, g1, g2, cnt;
    double sum;

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++)
    {
        min = m;
        max = 0;
        cnt = 0;
        sum = 0;
        scanf("%d", &g2);
        for (j = 0; j < n - 1; j++)
        {
            scanf("%d", &g1);
            if (g1 >= 0 && g1 <= m)
            {
                sum += g1;
                if (max < g1)
                {
                    max = g1;
                }
                if (min > g1)
                {
                    min = g1;
                }
                cnt++;
            }
        }
        sum -= (min + max);
        sum /= (cnt - 2);
        printf("%d\n", (int)((sum + g2) / 2 + 0.5));
    }

    return 0;
}