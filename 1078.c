#include <stdio.h>

int main()
{
    int cnt = 1, i = 0, sum = 0;
    char c, str[1001];

    scanf("%c", &c);
    getchar();
    gets(str);

    while (str[i] != '\0')
    {
        if (c == 'C')
        {
            if (str[i] == str[i + 1])
            {
                cnt++;
            }
            else
            {
                if (cnt != 1)
                {
                    printf("%d", cnt);
                }
                printf("%c", str[i]);
                cnt = 1;
            }
        }
        else
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                sum = sum * 10 + (str[i] - '0');
            }
            else if (sum != 0)
            {
                while (sum--)
                {
                    printf("%c", str[i]);
                }
                sum = 0;
            }
            else
            {
                printf("%c", str[i]);
            }
        }
        i++;
    }

    return 0;
}