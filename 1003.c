#include <stdio.h>

int main()
{
	int n, i, j, flag, cnt0, cnt1, cnt2;
	char str[100];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%s", str);

		flag = 0;
		cnt0 = 0;
		cnt1 = 0;
		cnt2 = 0;
		j = 0;
		while (str[j] != '\0')
		{
			if (str[j] == 'P' && flag == 0)
			{
				flag = 1;
			}
			else if (str[j] == 'A')
			{
				if (flag == 0)
				{
					cnt0++;
				}
				else if (flag == 1)
				{
					cnt1++;
				}
				else
				{
					cnt2++;
				}
			}
			else if (str[j] == 'T' && flag == 1)
			{
				flag = 2;
			}
			else
			{
				flag = 3;
				break;
			}
			j++;
		}

		if (flag != 2 || cnt0 * cnt1 != cnt2 || cnt1 == 0)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}

	return 0;
}