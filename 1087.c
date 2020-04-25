#include <stdio.h>

int main()
{
    int n, i, cnt = 0, A[100000] = {0}, sum;

    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        sum = i / 2 + i / 3 + i / 5;
        if (A[sum] == 0)
        {
            A[sum] = 1;
            cnt++;
        }
    }

    printf("%d", cnt);

    return 0;
}