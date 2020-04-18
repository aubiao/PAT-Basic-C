#include <stdio.h>

int UpSort(int n)
{
	int A[4] = {0}, i = 0, flag, j, temp;

	while (n != 0)
	{
		A[i++] = n % 10;
		n /= 10;
	}

	for (i = 0; i < 3; i++)
	{
		flag = 0;
		for (j = 3; j > i; j--)
		{
			if (A[j] > A[j - 1])
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

	for (i = 0; i < 4; i++)
	{
		n = n * 10 + A[i];
	}

	return n;
}

int DownSort(int n)
{
	int A[4] = {0}, i = 0, flag, j, temp;

	while (n != 0)
	{
		A[i++] = n % 10;
		n /= 10;
	}

	for (i = 0; i < 3; i++)
	{
		flag = 0;
		for (j = 3; j > i; j--)
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

	for (i = 0; i < 4; i++)
	{
		n = n * 10 + A[i];
	}

	return n;
}

int main()
{
	int n, A[4], max = 0, min;

	scanf("%d", &n);

	while ((n != 6174 || max == 0) && n != 0000)
	{
		max = UpSort(n);
		min = DownSort(n);
		n = max - min;
		printf("%04d - %04d = %04d\n", max, min, n);
	}

	return 0;
}