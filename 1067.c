#include <stdio.h>

int cmp(char *str, char *str1)
{
    int i = 0;

    while (str[i] != '\0' && str1[i] != '\0' && str[i] == str1[i])
    {
        i++;
    }

    if (str[i] != '\0' || str1[i] != '\0' || str[i] != str1[i])
    {
        return 0;
    }

    return 1;
}

int main()
{
    int n, cnt = 0, flag = 0;
    char str[30], str1[100];

    scanf("%s %d", str, &n);

    getchar();
    while (n > cnt)
    {
        gets(str1);
        if (str1[0] == '#' && str1[1] == '\0')
        {
            flag = 1;
            break;
        }
        if (cmp(str, str1))
        {
            printf("Welcome in\n");
            flag = 1;
            break;
        }
        else
        {
            printf("Wrong password: %s\n", str1);
        }
        cnt++;
    }

    if (flag == 0)
    {
        printf("Account locked\n");
    }

    return 0;
}