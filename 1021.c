#include <stdio.h>

int main()
{
	char c;
	int A[10] = {0}, i;

	while ((c = getchar()) != '\n')
	{
		A[c - '0']++;
	}

	for (i = 0; i < 10; i++)
	{
		if (A[i] != 0)
		{
			printf("%d:%d\n", i, A[i]);
		}
	}

	return 0;
}