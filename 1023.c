#include <stdio.h>

int main()
{
	int A[10], i;

	for (i = 0; i < 10; i++)
	{
		scanf("%d", &A[i]);
	}

	i = 1;
	do
	{
		if (A[i] != 0)
		{
			printf("%d", i);
			A[i]--;
			break;
		}
	} while (i++);

	for (i = 0; i < 10; i++)
	{
		while (A[i] != 0)
		{
			printf("%d", i);
			A[i]--;
		}
	}

	return 0;
}