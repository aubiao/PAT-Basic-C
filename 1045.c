#include <stdio.h>

int Partation(int A[], int low, int high)
{
	int temp = A[low];
	int index = low;

	while (low < high)
	{
		while (low < high && temp < A[high])
			high--;
		A[low] = A[high];
		while (low < high && temp > A[low])
			low++;
		A[high] = A[low];
	}

	A[low] = temp;

	return low;
}

void QuickSort(int A[], int low, int high)
{
	int a;

	if (low < high)
	{
		a = Partation(A, low, high);
		QuickSort(A, low, a - 1);
		QuickSort(A, a + 1, high);
	}
}

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void PreDown(int A[], int i, int n)
{
	int temp, child;

	for (temp = A[i]; i * 2 + 1 < n; i = child)
	{
		child = 2 * i + 1;
		if (child < n - 1 && A[child + 1] > A[child])
			child++;
		if (A[child] > temp)
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
	int n, i, cnt = 0, A[100000], B[100000], C[100000], max = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
		B[i] = A[i];
	}

	//	QuickSort(A,0,n - 1);
	HeapSort(A, n);

	for (i = 0; i < n; i++)
	{
		if (max < B[i])
		{
			max = B[i];
			if (B[i] == A[i])
			{
				C[cnt] = A[i];
				cnt++;
			}
		}
	}

	printf("%d\n", cnt);

	for (i = 0; i < cnt; i++)
	{
		if (i != 0)
		{
			printf(" ");
		}
		printf("%d", C[i]);
	}

	printf("\n");

	return 0;
}