#include <stdio.h>

int main()
{
	int n, temp, i, j, k = 1;
	char c;

	scanf("%d %c", &n, &c);

	temp = n - 1;

	while (temp >= (k + 2) * 2)
	{
		k += 2;
		temp -= k * 2;
	}

	for (i = k; i > 1; i -= 2)
	{
		for (j = 0; j < (k - i) / 2; j++)
		{
			printf(" ");
		}
		for (j = 0; j < i; j++)
		{
			printf("%c", c);
		}
		printf("\n");
	}

	while ((k - i) / 2 > 0)
	{
		printf(" ");
		i += 2;
	}
	printf("%c\n", c);

	for (i = 3; i <= k; i += 2)
	{
		for (j = 0; j < (k - i) / 2; j++)
		{
			printf(" ");
		}
		for (j = 0; j < i; j++)
		{
			printf("%c", c);
		}
		printf("\n");
	}

	printf("%d", temp);

	return 0;
}