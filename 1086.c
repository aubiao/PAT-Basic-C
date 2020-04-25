#include <stdio.h>

int main()
{
    int a, b, sum, i, cnt = 0, A[7] = {0}, flag = 0;

    scanf("%d %d", &a, &b);

    sum = a * b;

    while (sum > 0)
    {
        A[cnt] = sum % 10;
        sum /= 10;
        cnt++;
    }

    for (i = 0; i < cnt; i++)
    {
        if (flag != 0 || A[i] != 0)
        {
            flag = 1;
            printf("%d", A[i]);
        }
    }

    return 0;
}