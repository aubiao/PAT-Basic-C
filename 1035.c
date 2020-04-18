#include <stdio.h>

void Sort(int A[], int start, int end)
{
	int i, flag, j, temp;
	for (i = start; i < end - 1; i++)
	{
		flag = 0;
		for (j = end - 1; j > i; j--)
		{
			if (A[j] < A[j - 1])
			{
				temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

int main()
{
	int n, i, j, k, flag, print = 0, temp, A[100], B[100], C[100];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
		C[i] = A[i];
	}

	for (i = 0; i < n; i++)
	{
		scanf("%d", &B[i]);
	}

	for (i = 1; i < n; i++)
	{
		flag = 0;
		for (j = 0; j < i; j++)
		{
			if (A[i] < A[j])
			{
				temp = A[i];
				for (k = i - 1; k >= j; k--)
				{
					A[k + 1] = A[k];
				}
				A[j] = temp;
				break;
			}
		}
		if (print == 0)
		{
			for (k = 0; k < n; k++)
			{
				if (A[k] != B[k])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				printf("Insertion Sort\n");
				print = 1;
			}
		}
		else
		{
			for (k = 0; k < n; k++)
			{
				if (k != 0)
				{
					printf(" ");
				}
				printf("%d", A[k]);
			}
			break;
		}
	}

	if (print == 0)
	{
		k = 1;
		while (k < n)
		{
			flag = 0;
			k *= 2;
			for (i = 0; i < n / k; i++)
			{
				Sort(C, i * k, i * k + k);
			}
			Sort(C, i * k, n);
			if (print == 0)
			{
				for (j = 0; j < n; j++)
				{
					if (C[j] != B[j])
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					printf("Merge Sort\n");
					print = 1;
				}
			}
			else
			{
				for (j = 0; j < n; j++)
				{
					if (j != 0)
					{
						printf(" ");
					}
					printf("%d", C[j]);
				}
				break;
			}
		}
	}

	return 0;
}