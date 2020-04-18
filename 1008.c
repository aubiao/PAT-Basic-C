#include <stdio.h>

void swap(int A[], int low, int high)
{
	int temp;

	while (low < high)
	{
		temp = A[low];
		A[low] = A[high];
		A[high] = temp;
		low++;
		high--;
	}
}

int main()
{
	int n, m, i, A[101];

	scanf("%d %d", &n, &m);

	m %= n;

	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}

	if (m != 0)
	{
		swap(A, 0, n - m - 1);
		swap(A, n - m, n - 1);
		swap(A, 0, n - 1);
	}

	for (i = 0; i < n; i++)
	{
		if (i != 0)
		{
			printf(" ");
		}
		printf("%d", A[i]);
	}

	return 0;
}