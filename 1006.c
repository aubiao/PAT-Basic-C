#include <stdio.h>

int main()
{
	int n, sum = 0, cnt = 0, i = 1;

	scanf("%d", &n);

	while (n != 0)
	{
		sum = sum * 10 + n % 10;
		n /= 10;
		cnt++;
	}

	while (sum != 0)
	{
		n = sum % 10;
		while (n--)
		{
			if (cnt == 3)
			{
				printf("B");
			}
			else if (cnt == 2)
			{
				printf("S");
			}
			else
			{
				printf("%d", i);
				i++;
			}
		}
		sum /= 10;
		cnt--;
	}

	return 0;
}