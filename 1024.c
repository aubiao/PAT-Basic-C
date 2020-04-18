#include <stdio.h>

int main()
{
	char c;
	int flag = 0, cnt = 0, A[10000], i = 1, n = 0, b = 0;

	c = getchar();

	if (c == '-')
	{
		printf("-");
	}

	c = getchar();

	A[n++] = c - '0';

	c = getchar();

	while ((c = getchar()) != 'E')
	{
		A[n++] = c - '0';
	}

	c = getchar();

	if (c == '+')
	{
		flag = 1;
	}
	else
	{
		flag = -1;
	}

	while ((c = getchar()) != '\n')
	{
		b = b * 10 + (c - '0');
	}

	if (flag == 1)
	{
		printf("%d", A[0]);
		while (b-- != 0)
		{
			if (i < n)
			{
				printf("%d", A[i]);
			}
			else
			{
				printf("0");
			}
			i++;
		}
		if (i < n)
		{
			printf(".");
			while (i < n)
			{
				printf("%d", A[i]);
				i++;
			}
		}
	}
	else
	{
		printf("0.");
		while (b > 1)
		{
			printf("0");
			b--;
		}
		printf("%d", A[0]);
		while (i < n)
		{
			printf("%d", A[i]);
			i++;
		}
	}

	return 0;
}