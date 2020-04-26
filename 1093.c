#include <stdio.h>

int main()
{
    int n, i, A[100] = {0}, a;
    char str1[1000001], str2[1000001];

    gets(str1);
    gets(str2);

    for (i = 0; str1[i] != '\0'; i++)
    {
        a = str1[i] - ' ';
        if (A[a] == 0)
        {
            printf("%c", str1[i]);
            A[a] = 1;
        }
    }

    for (i = 0; str2[i] != '\0'; i++)
    {
        a = str2[i] - ' ';
        if (A[a] == 0)
        {
            printf("%c", str2[i]);
            A[a] = 1;
        }
    }

    return 0;
}