#include <stdio.h>

int main()
{
	int n, i, A[100001] = {0}, max = 0, maxi = 0, k, score;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &k, &score);
		A[k] += score;
		if (max < A[k])
		{
			max = A[k];
			maxi = k;
		}
	}

	printf("%d %d", maxi, max);

	return 0;
}