#include <stdio.h>

int main()
{
    int m, x, y, i, A[2], d;
    char str[3][5] = {"Cong", "Ping", "Gai"};
    double c;

    scanf("%d %d %d", &m, &x, &y);

    for (i = 99; i >= 10; i--)
    {
        A[0] = i;
        A[1] = A[0] % 10 * 10 + A[0] / 10;
        c = A[1] * 1.0 / y;
        d = A[0] - A[1];
        if (d < 0)
        {
            d *= -1;
        }
        if (d == c * x)
        {
            break;
        }
    }

    if (i >= 10)
    {
        printf("%d", A[0]);
        for (i = 0; i < 2; i++)
        {
            if (A[i] > m)
            {
                d = 0;
            }
            else if (A[i] == m)
            {
                d = 1;
            }
            else
            {
                d = 2;
            }
            printf(" %s", str[d]);
        }
        if (c > m)
        {
            printf(" %s", str[0]);
        }
        else if (c == m)
        {
            printf(" %s", str[1]);
        }
        else
        {
            printf(" %s", str[2]);
        }
    }
    else
    {
        printf("No Solution\n");
    }

    return 0;
}