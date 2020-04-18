#include <stdio.h>

int main()
{
	int n, i, w = 0, A[2][3] = {0}, win;
	char str1, str2;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		getchar();
		scanf("%c %c", &str1, &str2);

		if (str1 == str2)
		{
			w++;
		}
		else if (str1 == 'B' && str2 == 'C')
		{
			A[0][0]++;
		}
		else if (str1 == 'C' && str2 == 'J')
		{
			A[0][1]++;
		}
		else if (str1 == 'J' && str2 == 'B')
		{
			A[0][2]++;
		}
		else if (str1 == 'C' && str2 == 'B')
		{
			A[1][0]++;
		}
		else if (str1 == 'J' && str2 == 'C')
		{
			A[1][1]++;
		}
		else if (str1 == 'B' && str2 == 'J')
		{
			A[1][2]++;
		}
	}

	win = A[0][0] + A[0][1] + A[0][2];

	printf("%d %d %d\n", win, w, n - win - w);
	printf("%d %d %d\n", n - win - w, w, win);
	for (i = 0; i < 2; i++)
	{
		if (A[i][0] >= A[i][1] && A[i][0] >= A[i][2])
		{
			printf("B");
		}
		else if (A[i][1] > A[i][0] && A[i][1] >= A[i][2])
		{
			printf("C");
		}
		else if (A[i][2] > A[i][0] && A[i][2] > A[i][1])
		{
			printf("J");
		}
		if (i == 0)
		{
			printf(" ");
		}
	}

	return 0;
}