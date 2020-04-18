#include <stdio.h>

int main()
{
	int n, i, A[101] = {0}, temp, num;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &num);
		A[num] = 1;
	}

	for (i = 2; i < 101; i++)
	{
		if (A[i] == 1)
		{
			temp = i;
			while (temp != 1)
			{
				if (temp % 2 == 0)
				{
					temp /= 2;
				}
				else
				{
					temp = (temp * 3 + 1) / 2;
				}
				if (temp < 101 && A[temp] == 1)
				{
					A[temp] = 2;
				}
			}
		}
	}

	temp = 0;
	for (i = 100; i >= 0; i--)
	{
		if (A[i] == 1)
		{
			if (temp == 1)
			{
				printf(" ");
			}
			temp = 1;
			printf("%d", i);
		}
	}

	return 0;
}