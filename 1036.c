#include <stdio.h>

int main()
{
	int i, n, m, j;
	char c;

	scanf("%d %c", &n, &c);

	for (i = 0; i < n; i++)
	{
		printf("%c", c);
	}
	printf("\n");

	m = n / 2 - 2;
	if (n % 2 == 1)
	{
		m++;
	}

	for (i = 0; i < m; i++)
	{
		printf("%c", c);
		for (j = 0; j < n - 2; j++)
		{
			printf(" ");
		}
		printf("%c\n", c);
	}

	for (i = 0; i < n; i++)
	{
		printf("%c", c);
	}
	printf("\n");

	return 0;
}