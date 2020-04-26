#include <stdio.h>
#include <math.h>

int is_prime(int a)
{
    int i;

    for (i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int l, k, i, j, A[1000], sum, flag = 0;
    char c;

    scanf("%d %d", &l, &k);
    getchar();

    for (i = 0; i < l; i++)
    {
        c = getchar();
        A[i] = c - '0';
    }

    for (i = 0; i <= (l - k); i++)
    {
        sum = 0;
        for (j = i; j < (i + k); j++)
        {
            sum = sum * 10 + A[j];
        }
        if (is_prime(sum))
        {
            printf("%0*d\n", k, sum);
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        printf("404\n");
    }

    return 0;
}