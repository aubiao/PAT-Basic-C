#include <stdio.h>

int main()
{
	int i, flag = 0, a, b;
	char c;

	do
	{
		scanf("%d %d", &a, &b);
		if (b != 0)
		{
			if (flag == 1)
			{
				printf(" ");
			}
			a *= b;
			b--;
			printf("%d %d", a, b);
			flag = 1;
		}
		else if (flag == 0 && b == 0)
		{
			printf("%d %d", 0, 0);
			break;
		}
	} while ((c = getchar()) == ' ');

	return 0;
}