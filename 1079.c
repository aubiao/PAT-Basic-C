#include <stdio.h>
#include <string.h>

int ispall(int A[], int len)
{
    int i;
    for (i = 0; i < len / 2; i++)
    {
        if (A[i] != A[len - i - 1])
        {
            return 0;
        }
    }

    return 1;
}

int add(int A[], int len, char *str)
{
    int i, sum, temp = 0;

    for (i = 0; i < len; i++)
    {
        sum = A[i] + (str[i] - '0') + temp;
        A[i] = sum % 10;
        temp = sum / 10;
    }
    if (temp != 0)
    {
        A[len] = temp;
        len++;
    }

    for (i = 0; i < len; i++)
    {
        str[i] = A[len - i - 1] + '0';
    }
    str[i] = '\0';

    return len;
}

int main()
{
    int A[1010], i, j, len, flag = 0;
    char str[1010];

    gets(str);
    len = strlen(str);

    for (i = 0; i < len; i++)
    {
        A[len - i - 1] = str[i] - '0';
    }

    for (i = 0; i < 10; i++)
    {
        if (ispall(A, len))
        {
            printf("%s is a palindromic number.\n", str);
            flag = 1;
            break;
        }
        else
        {
            printf("%s + ", str);
            for (j = len - 1; j >= 0; j--)
            {
                printf("%c", str[j]);
            }
            len = add(A, len, str);
            printf(" = %s\n", str);
        }
    }

    if (flag == 0)
    {
        printf("Not found in 10 iterations.\n");
    }

    return 0;
}