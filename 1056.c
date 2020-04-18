#include <stdio.h>

int main()
{
	int n, A[10], i, j, sum = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i != j)
			{
				sum += A[i] * 10 + A[j];
			}
		}
	}

	printf("%d", sum);

	return 0;
}