#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
	int i;

	for (i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int k, n, i, A[10000] = {0};

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &k);
		A[k] = i + 1;
	}

	scanf("%d", &k);

	for (i = 0; i < k; i++)
	{
		scanf("%d", &n);
		if (A[n] == 1)
		{
			printf("%04d: Mystery Award\n", n);
			A[n] = -1;
		}
		else if (A[n] == 0)
		{
			printf("%04d: Are you kidding?\n", n);
		}
		else if (A[n] == -1)
		{
			printf("%04d: Checked\n", n);
		}
		else if (is_prime(A[n]))
		{
			printf("%04d: Minion\n", n);
			A[n] = -1;
		}
		else
		{
			printf("%04d: Chocolate\n", n);
			A[n] = -1;
		}
	}

	return 0;
}