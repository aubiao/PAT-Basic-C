#include <stdio.h>
#include <math.h>

int main()
{
    int n, maxuse, minuse, i, x, y, use;
    double max = 0, min = 150, sum;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &use, &x, &y);
        sum = sqrt(x * x + y * y);
        if (max < sum)
        {
            maxuse = use;
            max = sum;
        }
        if (min > sum)
        {
            minuse = use;
            min = sum;
        }
    }

    printf("%04d %04d", minuse, maxuse);

    return 0;
}