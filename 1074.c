#include <stdio.h>
#include <string.h>

int main()
{
    char a[21], b[21], c[21];
    int lena, lenb, lenc, temp = 0, A, B, i, flag = 0;

    scanf("%s", a);
    scanf("%s", b);
    scanf("%s", c);

    lena = strlen(a) - 1;
    lenb = strlen(b) - 1;
    lenc = strlen(c) - 1;

    while (lenb >= 0 && lenc >= 0)
    {
        A = a[lena] - '0';
        B = (b[lenb] - '0') + (c[lenc] - '0') + temp;
        if (A == 0)
        {
            A = 10;
        }
        a[lena] = B % A + '0';
        temp = B / A;
        lena--;
        lenb--;
        lenc--;
    }

    while (lenb >= 0)
    {
        A = a[lena] - '0';
        B = b[lenb] - '0' + temp;
        if (A == 0)
        {
            A = 10;
        }
        a[lena] = B % A + '0';
        temp = B / A;
        lena--;
        lenb--;
    }

    while (lenc >= 0)
    {
        A = a[lena] - '0';
        B = c[lenc] - '0' + temp;
        if (A == 0)
        {
            A = 10;
        }
        a[lena] = B % A + '0';
        temp = B / A;
        lena--;
        lenc--;
    }

    while (temp != 0 && lena >= 0)
    {
        A = a[lena] - '0';
        a[lena] = temp % A + '0';
        temp /= A;
        lena--;
    }

    if (temp != 0)
    {
        flag = 1;
        printf("%d", temp);
    }

    for (i = lena + 1; a[i] != '\0'; i++)
    {
        if(!(flag == 0 && a[i] == '0'))
        {
            flag = 1;
            printf("%c",a[i]);
        }
    }

    if(flag == 0)
    {
        printf("0");
    }

    return 0;
}