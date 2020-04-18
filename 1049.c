#include <stdio.h>

int main()
{
	int n, i;
	double sum = 0, m;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lf", &m);
		sum += m * (i + 1) * (n - i);
	}

	printf("%.2f\n", sum);

	return 0;
}