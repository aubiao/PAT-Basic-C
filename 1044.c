#include <stdio.h>

char A[13][5] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char B[12][5] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int cmp(char str[], int low, int high)
{
	int i, j, k, flag;

	for (i = 0; i < 12; i++)
	{
		j = 0;
		k = low;
		flag = 0;
		while (B[i][j] != '\0' && k <= high)
		{
			if (str[k] != B[i][j])
			{
				flag = 1;
				break;
			}
			k++;
			j++;
		}
		if (flag == 0)
		{
			return (i + 1) * 13;
		}
	}

	for (i = 0; i < 13; i++)
	{
		j = 0;
		k = low;
		flag = 0;
		while (A[i][j] != '\0' && k <= high)
		{
			if (str[k] != A[i][j])
			{
				flag = 1;
				break;
			}
			k++;
			j++;
		}
		if (flag == 0)
		{
			return i;
		}
	}

	return 0;
}

int main()
{
	char str[10], c;
	int n, i, j, k = 0, sum = 0, temp = 0;

	scanf("%d", &n);
	getchar();

	for (i = 0; i < n; i++)
	{
		k = 0;
		while ((c = getchar()) != '\n')
		{
			str[k] = c;
			k++;
		}
		str[k] = '\0';
		j = 0;
		sum = 0;
		temp = 0;
		if (str[0] >= '0' && str[0] <= '9')
		{
			while (str[j] != '\0')
			{
				sum = sum * 10 + (str[j] - '0');
				j++;
			}
			temp = sum / 13;
			sum %= 13;
			if (temp != 0)
			{
				printf("%s", B[temp - 1]);
				if (sum != 0)
				{
					printf(" ");
				}
			}
			if (sum != 0 || temp == 0)
			{
				printf("%s", A[sum]);
			}
			printf("\n");
		}
		else
		{
			while (str[j] != '\0')
			{
				if (str[j] == ' ')
				{

					sum = cmp(str, 0, j - 1);
					temp = j + 1;
				}
				j++;
			}
			sum += cmp(str, temp, j - 1);
			printf("%d\n", sum);
		}
	}

	return 0;
}