#include <stdio.h>

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int n1, n2, m1, m2, k, a, b, i, flag = 0, temp;

    scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);

    a = n1 * k / m1;
    b = n2 * k / m2;
    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
        temp = n1;
        n1 = n2;
        n2 = temp;
        temp = m1;
        m1 = m2;
        m2 = temp;
    }

    a++;
    if (n2 * k % m2 == 0)
    {
        b--;
    }

    for (i = a; i <= b; i++)
    {
        if (gcd(i, k) == 1)
        {
            if (flag == 1)
            {
                printf(" ");
            }
            else
            {
                flag = 1;
            }
            printf("%d/%d", i, k);
        }
    }

    return 0;
}