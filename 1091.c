#include <stdio.h>

int is_suffix(int a, int b)
{
    while (b > 0)
    {
        if ((a % 10) != (b % 10))
        {
            return 0;
        }
        else
        {
            a /= 10;
            b /= 10;
        }
    }
    return 1;
}

int main()
{
    int n, A[20], i, j, sum;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 1; j < 10; j++)
        {
            sum = A[i] * A[i];
            sum *= j;
            if (is_suffix(sum, A[i]))
            {
                printf("%d %d\n", j, sum);
                break;
            }
        }
        if (j > 9)
        {
            printf("No\n");
        }
    }

    return 0;
}