#include <stdio.h>

int main()
{
	char str[4][61];
	int i = 0, n, k = 0, flag = 0, key1, key2;
	char day[][5] = {
		"MON",
		"TUE",
		"WED",
		"THU",
		"FRI",
		"SAT",
		"SUN"};

	while (i < 4)
	{
		scanf("%s", str[i++]);
	}

	while (k != 3)
	{
		for (i = 0; str[k][i] != '\0' || str[k + 1][i] != '\0'; i++)
		{
			if (str[k][i] == str[k + 1][i])
			{
				if (k == 0)
				{
					if (flag == 0 && str[k][i] >= 'A' && str[k][i] <= 'G')
					{
						key1 = str[k][i] - 'A';
						flag = 1;
					}
					else if (flag == 1)
					{
						if (str[k][i] >= '0' && str[k][i] <= '9')
						{
							key2 = str[k][i] - '0';
							k = 2;
							break;
						}
						else if (str[k][i] >= 'A' && str[k][i] <= 'N')
						{
							key2 = str[k][i] - 'A' + 10;
							k = 2;
							break;
						}
					}
				}
				else
				{
					if ((str[k][i] >= 'A' && str[k][i] <= 'Z') || (str[k][i] >= 'a' && str[k][i] <= 'z'))
					{
						printf("%s %02d:%02d\n", day[key1], key2, i);
						k = 3;
						break;
					}
				}
			}
		}
	}

	return 0;
}