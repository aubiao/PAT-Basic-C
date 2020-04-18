#include <stdio.h>

int main()
{
	int i, A[6] = {0}, flag = 1;
	char c;

	while ((c = getchar()) != '\n')
	{
		if (c == 'P')
		{
			A[0]++;
		}
		else if (c == 'A')
		{
			A[1]++;
		}
		else if (c == 'T')
		{
			A[2]++;
		}
		else if (c == 'e')
		{
			A[3]++;
		}
		else if (c == 's')
		{
			A[4]++;
		}
		else if (c == 't')
		{
			A[5]++;
		}
	}

	while (flag == 1)
	{
		flag = 0;
		if (A[0] != 0)
		{
			A[0]--;
			flag = 1;
			printf("P");
		}
		if (A[1] != 0)
		{
			A[1]--;
			flag = 1;
			printf("A");
		}
		if (A[2] != 0)
		{
			A[2]--;
			flag = 1;
			printf("T");
		}
		if (A[3] != 0)
		{
			A[3]--;
			flag = 1;
			printf("e");
		}
		if (A[4] != 0)
		{
			A[4]--;
			flag = 1;
			printf("s");
		}
		if (A[5] != 0)
		{
			A[5]--;
			flag = 1;
			printf("t");
		}
	}

	return 0;
}