#include <stdio.h>

int main()
{
	int n, cnt = 0;

	scanf("%d", &n);

	while (n != 1)
	{
		if (n % 2 == 0)
		{
			n /= 2;
		}
		else
		{
			n = (n * 3 + 1) / 2;
		}
		cnt++;
	}

	printf("%d", cnt);

	return 0;
}