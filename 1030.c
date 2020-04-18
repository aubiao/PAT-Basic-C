#include <stdio.h>

int Partition(int A[], int low, int high)
{
	int temp = A[low];

	while (low < high)
	{
		while (low < high && temp <= A[high])
		{
			high--;
		}
		A[low] = A[high];
		while (low < high && temp >= A[low])
		{
			low++;
		}
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
		a = Partition(A, low, high);
		QuickSort(A, low, a - 1);
		QuickSort(A, a + 1, high);
	}
}

int compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void PreDown(int A[], int i, int n)
{
	int child, temp;
	for (temp = A[i]; 2 * i + 1 < n; i = child)
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
	int n, i, j, A[100000], p, max = 0, cnt;
	long long int m;

	scanf("%d %d", &n, &p);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}

	//	QuickSort(A,0,n-1);
	HeapSort(A, n);
	//	qsort(A,n,sizeof(int),compare);

	for (i = 0; i < n; i++)
	{
		m = 1L * A[i] * p;
		for (j = i + max; j < n; j++)
		{
			if (m >= A[j])
			{
				cnt = j - i + 1;
				if (cnt > max)
				{
					max = cnt;
				}
			}
			else
			{
				break;
			}
		}
	}

	printf("%d", max);

	return 0;
}