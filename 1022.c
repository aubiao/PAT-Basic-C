#include <stdio.h>

int main()
{
	int d, A[100], i = 0, j;
	long long int a, b;

	scanf("%lld %lld %d", &a, &b, &d);

	a += b;

	while (a > 0)
	{
		A[i++] = a % d;
		a /= d;
	}

	for (j = i - 1; j >= 0; j--)
	{
		printf("%d", A[j]);
	}

	if (i == 0)
	{
		printf("0");
	}

	return 0;
}