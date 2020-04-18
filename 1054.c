#include <stdio.h>
#include <string.h>
int main()
{
	int n, i, j, cnt = 0, flag, flag1, len;
	double sum = 0, a, flag2;
	char c[100];
	scanf("%d", &n);
	cnt = n;
	for (i = 0; i < n; i++)
	{
		scanf("%s", c);
		len = strlen(c);
		a = 0;
		flag = 0;
		flag1 = 0;
		flag2 = 1.0;
		for (j = 0; j < len; j++)
		{
			if ((c[j] < '0' || c[j] > '9') && c[j] != '-' && c[j] != '.')
			{
				printf("ERROR: %s is not a legal number\n", c);
				a = 0;
				cnt--;
				break;
			}
			else if (c[j] == '-' && j != 0)
			{
				printf("ERROR: %s is not a legal number\n", c);
				a = 0;
				cnt--;
				break;
			}
			else if (c[j] == '.' && flag == 1)
			{
				printf("ERROR: %s is not a legal number\n", c);
				a = 0;
				cnt--;
				break;
			}
			else if (c[j] == '-' && j == 0)
			{
				flag1 = 1;
			}
			else if (c[j] == '.' && flag == 0)
			{
				flag = 1;
			}
			else if (flag == 0)
			{
				a = a * 10 + c[j] - '0';
			}
			else if (flag == 1)
			{
				flag2 *= 0.1;
				if (flag2 < 0.01)
				{
					printf("ERROR: %s is not a legal number\n", c);
					a = 0;
					cnt--;
					break;
				}
				a += (c[j] - '0') * flag2;
			}
		}
		if (a < -1000 || a > 1000)
		{
			printf("ERROR: %s is not a legal number\n", c);
			a = 0;
			cnt--;
		}
		if (flag1 == 1)
		{
			a = -a;
		}
		sum += a;
	}
	if (cnt == 0)
	{
		printf("The average of 0 numbers is Undefined");
	}
	else if (cnt == 1)
	{
		printf("The average of 1 number is %.2f", sum);
	}
	else
	{
		printf("The average of %d numbers is %.2f", cnt, sum / cnt);
	}
	return 0;
}