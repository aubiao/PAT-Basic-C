#include <stdio.h>

int main()
{
    int n, d, cnt, k, i, j, cnt1 = 0, cnt2 = 0;
    double e, data;

    scanf("%d %lf %d", &n, &e, &d);

    for (i = 0; i < n; i++)
    {
        cnt = 0;
        scanf("%d", &k);
        for (j = 0; j < k; j++)
        {
            scanf("%lf", &data);
            if (data < e)
            {
                cnt++;
            }
        }
        if (cnt * 1.0 / k > 0.5)
        {
            if (k > d)
            {
                cnt2++;
            }
            else
            {
                cnt1++;
            }
        }
    }

    printf("%.1f%% %.1f%%", cnt1 * 1.0 / n * 100, cnt2 * 1.0 / n * 100);

    return 0;
}