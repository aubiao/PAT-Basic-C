#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, j, flags, flagz, len;
    char str[81];

    scanf("%d", &n);
    getchar();

    for (i = 0; i < n; i++)
    {
        flags = 0;
        flagz = 0;
        gets(str);
        len = strlen(str);
        if (len < 6)
        {
            printf("Your password is tai duan le.\n");
        }
        else
        {
            for (j = 0; str[j] != '\0'; j++)
            {
                if ((str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'A' && str[j] <= 'Z'))
                {
                    flagz = 1;
                }
                else if (str[j] >= '0' && str[j] <= '9')
                {
                    flags = 1;
                }
                else if (str[j] != '.')
                {
                    printf("Your password is tai luan le.\n");
                    flagz = -1;
                    break;
                }
            }
            if (flagz == 1 && flags == 0)
            {
                printf("Your password needs shu zi.\n");
            }
            else if (flagz == 0 && flags == 1)
            {
                printf("Your password needs zi mu.\n");
            }
            else if (flagz == 1 && flags == 1)
            {
                printf("Your password is wan mei.\n");
            }
        }
    }

    return 0;
}