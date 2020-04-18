#include <stdio.h>

int main()
{
	int B, R, i, j = 0, temp = 0;
	char A[1000], Q[1000];

	scanf("%s %d", &A, &B);

	for (i = 0; A[i] != '\0'; i++)
	{
		temp = temp * 10 + (A[i] - '0');
		if (temp >= B)
		{
			Q[j++] = temp / B + '0';
			temp %= B;
		}
		else if (i != 0)
		{
			Q[j++] = '0';
		}
	}

	if (j == 0)
	{
		Q[j++] = '0';
	}
	Q[j] = '\0';
	R = temp;

	printf("%s %d\n", Q, R);

	return 0;
}