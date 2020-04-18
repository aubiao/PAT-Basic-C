#include <stdio.h>
#include <math.h>

int main()
{
	int m, n, i, j, cnt = 0, flag, temp, cnt1 = 0;

	scanf("%d %d", &m, &n);

	for (i = 2; cnt < n; i++)
	{
		flag = 0;
		temp = i;
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			cnt++;
			if (cnt >= m && cnt <= n)
			{
				if (cnt1 != 0)
				{
					if (cnt1 % 10 == 0)
					{
						printf("\n");
					}
					else
					{
						printf(" ");
					}
				}
				cnt1++;
				printf("%d", i);
			}
		}
	}

	return 0;
}