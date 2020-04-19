#include <stdio.h>

int cmp(char *str1, char *str2)
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
        i++;

    if (str1[i] != '\0' || str2[i] != '\0' || str1[i] != str2[i])
    {
        return 0;
    }

    return 1;
}

void copy(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != '\0')
    {
        str2[i] = str1[i];
        i++;
    }
    str2[i] = '\0';
}

int main()
{
    int m, n, s, cnt = 0, i, j, flag;
    char luckyname[1000][21], name[21];

    scanf("%d %d %d", &m, &n, &s);

    for (i = 0; i < m; i++)
    {
        scanf("%s", name);
        if (s == (i + 1))
        {
            flag = 0;
            for (j = 0; j < cnt; j++)
            {
                if (cmp(name, luckyname[j]))
                {
                    s++;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                printf("%s\n", name);
                copy(name, luckyname[cnt]);
                cnt++;
                s += n;
            }
        }
    }

    if (cnt == 0)
    {
        printf("Keep going...\n");
    }

    return 0;
}