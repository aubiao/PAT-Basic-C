#include <stdio.h>

int main()
{
    int m, x, y, i, a, b, c, d;

    scanf("%d %d %d", &m, &x, &y);

    for (i = 99; i >= 10; i--)
    {
        a = i;
        b = a % 10 * 10 + a / 10;
        if (b % y != 0)
        {
            continue;
        }
        else
        {
            c = b / y;
            d = a - b;
            if (d < 0)
            {
                d *= -1;
            }
            if (d == c * x)
            {
                break;
            }
        }
    }

    if (i >= 10)
    {
        printf("%d %d %d\n", a, b, c);
    }
    else
    {
        printf("No Solution\n");
    }

    return 0;
}