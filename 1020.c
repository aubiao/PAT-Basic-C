#include <stdio.h>

int Partition(double A[][2], int low, int high)
{
	double a = A[low][0], b = A[low][1];
	double temp = b * 1.0 / a;

	while (low < high)
	{
		while (low < high && A[high][1] * 1.0 / A[high][0] <= temp)
		{
			high--;
		}
		A[low][0] = A[high][0];
		A[low][1] = A[high][1];
		while (low < high && A[low][1] * 1.0 / A[low][0] >= temp)
		{
			low++;
		}
		A[high][0] = A[low][0];
		A[high][1] = A[low][1];
	}

	A[low][0] = a;
	A[low][1] = b;

	return low;
}

void QuickSort(double A[][2], int low, int high)
{
	int a;

	if (low < high)
	{
		a = Partition(A, low, high);
		QuickSort(A, low, a - 1);
		QuickSort(A, a + 1, high);
	}
}

int main()
{
	int n, d, i, j, flag;
	double sum = 0, A[1000][2], temp[2];

	scanf("%d %d", &n, &d);

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%lf", &A[j][i]);
		}
	}

	QuickSort(A, 0, n - 1);

	for (i = 0; i < n; i++)
	{
		if (d > A[i][0])
		{
			d -= A[i][0];
			sum += A[i][1];
		}
		else
		{
			sum += A[i][1] * 1.0 * d / A[i][0];
			break;
		}
	}

	printf("%.2f", sum);

	return 0;
}