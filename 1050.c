#include <stdio.h>
#include <math.h>

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void PreDown(int A[], int i, int n)
{
	int temp, child;

	for (temp = A[i]; 2 * i + 1 < n; i = child)
	{
		child = 2 * i + 1;
		if (child < n - 1 && A[child + 1] < A[child])
			child++;
		if (temp > A[child])
			A[i] = A[child];
		else
			break;
	}

	A[i] = temp;
}

void HeapSort(int A[], int n)
{
	int i;

	for (i = n / 2; i >= 0; i--)
	{
		PreDown(A, i, n);
	}

	for (i = n - 1; i > 0; i--)
	{
		Swap(&A[0], &A[i]);
		PreDown(A, 0, i);
	}
}

int main()
{
	int i, j, k = 0, w = 1, p = 0, q = 0, flag = 0, N, n, m, a, b, A[10001], B[10001][101];

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}

	HeapSort(A, N);

	n = sqrt(N);
	while (N % n != 0)
	{
		n--;
	}
	m = N / n;
	a = n;
	b = m;

	for (i = 0; i < N; i++)
	{
		B[p][q] = A[i];
		if (flag == 0)
		{
			if (n <= 1)
			{
				p++;
			}
			else
			{
				q++;
			}
			if (q == n - 1)
			{
				flag = 1;
				n--;
			}
		}
		else if (flag == 1)
		{
			if (m <= 1)
			{
				q--;
			}
			else
			{
				p++;
			}
			if (p == m - 1)
			{
				flag = 2;
				m--;
			}
		}
		else if (flag == 2)
		{
			q--;
			if (q == k)
			{
				flag = 3;
				k++;
			}
		}
		else if (flag == 3)
		{
			p--;
			if (p == w)
			{
				flag = 0;
				w++;
			}
		}
	}

	for (i = 0; i < b; i++)
	{
		for (j = 0; j < a; j++)
		{
			printf("%d", B[i][j]);
			if (j != a - 1)
			{
				printf(" ");
			}
			else
			{
				printf("\n");
			}
		}
	}

	return 0;
}