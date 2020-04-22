#include <stdio.h>

int main()
{
    int n, A[100], i, j;
    char a, b;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 4; j++)
        {
            getchar();
            scanf("%c-%c", &a, &b);
            if (b == 'T')
            {
                A[i] = a - 'A' + 1;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%d", A[i]);
    }

    return 0;
}