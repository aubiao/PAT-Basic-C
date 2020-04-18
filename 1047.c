#include <stdio.h>

int main()
{
	int n, p, q, i, score, A[1001] = {0}, max = 0, w = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d-%d %d", &p, &q, &score);
		A[p] += score;
		if (max < A[p])
		{
			w = p;
			max = A[p];
		}
	}

	printf("%d %d\n", w, max);

	return 0;
}