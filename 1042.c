#include <stdio.h>

int main()
{
	int i, max = 0, n = 0, A[30] = {0}, a = 0;
	char c;

	while ((c = getchar()) != '\n')
	{
		if (c >= 'A' && c <= 'Z')
		{
			a = c - 'A';
			A[a]++;
		}
		else if (c >= 'a' && c <= 'z')
		{
			a = c - 'a';
			A[a]++;
		}
		if (max < A[a] || (max == A[a] && n > a))
		{
			max = A[a];
			n = a;
		}
	}

	printf("%c %d\n", n + 'a', max);

	return 0;
}