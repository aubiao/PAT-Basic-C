#include <stdio.h>

int main()
{
	int n, cnt = 0, i, j, temp = 2, flag;

	scanf("%d", &n);

	for (i = 3; i <= n; i++)
	{

		flag = 0;

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
			if (i - temp == 2)
			{
				cnt++;
			}
			temp = i;
		}
	}

	printf("%d", cnt);

	return 0;
}