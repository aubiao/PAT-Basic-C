#include <stdio.h>

int main()
{
	int i, n, a, A[6] = {0}, flag = 1, cnt1 = 0, flag1 = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if (a % 5 == 0 && a % 2 == 0)
		{
			A[0] += a;
		}
		else if (a % 5 == 1)
		{
			A[1] += a * flag;
			flag *= -1;
			flag1 = 1;
		}
		else if (a % 5 == 2)
		{
			A[2]++;
		}
		else if (a % 5 == 3)
		{
			A[3] += a;
			cnt1++;
		}
		else if (a % 5 == 4)
		{
			if (A[4] < a)
			{
				A[4] = a;
			}
		}
	}

	for (i = 0; i < 5; i++)
	{
		if ((i != 1 && A[i] == 0) || (i == 1 && flag1 == 0))
		{
			printf("N");
		}
		else
		{
			if (i == 3)
			{
				printf("%.1f", A[i] * 1.0 / cnt1);
			}
			else
			{
				printf("%d", A[i]);
			}
		}
		if (i != 4)
		{
			printf(" ");
		}
	}

	return 0;
}