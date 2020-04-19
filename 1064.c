#include <stdio.h>

int main()
{
    int n, A[37] = {0}, a, i, sum, cnt = 0, flag = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
        sum = 0;
        while (a > 0)
        {
            sum += a % 10;
            a /= 10;
        }
        A[sum]++;
        if (A[sum] == 1)
        {
            cnt++;
        }
    }

    printf("%d\n", cnt);

    for (i = 0; i < 37; i++)
    {
        if (A[i] > 0)
        {
            if (flag == 0)
            {
                flag = 1;
            }
            else
            {
                printf(" ");
            }
            printf("%d", i);
        }
    }

    return 0;
}