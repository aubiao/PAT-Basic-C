#include <stdio.h>

int main()
{
	int n, i, k, A[101] = {0}, m;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &m);
		A[m]++;
	}

	scanf("%d", &k);

	for (i = 0; i < k; i++)
	{
		scanf("%d", &m);
		if (i != 0)
		{
			printf(" ");
		}
		printf("%d", A[m]);
	}

	return 0;
}