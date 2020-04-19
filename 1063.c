#include <stdio.h>
#include <math.h>

int main()
{
    int n, i;
    double a, b, max = 0, temp;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%lf %lf", &a, &b);
        temp = sqrt(a * a + b * b);
        if (max < temp)
        {
            max = temp;
        }
    }

    printf("%.2f", max);

    return 0;
}