#include <stdio.h>

int main()
{
	int n, i, a, b, c, d, p = 0, q = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);

		if (b != d)
		{
			if (a + c == b)
			{
				q++;
			}
			else if (a + c == d)
			{
				p++;
			}
		}
	}

	printf("%d %d", p, q);

	return 0;
}