#include <stdio.h>
#include <string.h>

int main()
{
	int n, i, len1, len2, k, a, flag = 0;
	char str1[101], str2[101];

	scanf("%s %s", str1, str2);

	len1 = strlen(str1);
	len2 = strlen(str2);
	k = len1 - 1;

	for (i = len2 - 1; i >= 0 && (k >= 0); i--)
	{
		if ((len2 - i) % 2 == 1)
		{
			a = ((str1[k--] - '0') + (str2[i] - '0')) % 13;
			if (a == 10)
			{
				str2[i] = 'J';
			}
			else if (a == 11)
			{
				str2[i] = 'Q';
			}
			else if (a == 12)
			{
				str2[i] = 'K';
			}
			else
			{
				str2[i] = a + '0';
			}
		}
		else
		{
			a = ((str2[i] - '0') - (str1[k--] - '0'));
			if (a < 0)
			{
				a += 10;
			}
			str2[i] = a + '0';
		}
	}

	for (i = 0; i <= k; i++)
	{
		if ((len1 - i) % 2 == 0)
		{
			if (str1[i] != '0')
			{
				printf("%d", 10 - (str1[i] - '0'));
			}
			else
			{
				printf("0");
			}
		}
		else
		{
			printf("%c", str1[i]);
		}
	}

	printf("%s\n", str2);

	return 0;
}