#include <stdio.h>

int main()
{
	int n, m[5], i, j;
	char c, str[3][10][5];

	for (i = 0; i < 3; i++)
	{
		j = 0;
		while ((c = getchar()) != '\n')
		{
			if (c == '[')
				scanf("%[^]]", str[i][j++]);
		}
	}

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 5; j++)
			scanf("%d", m + j);
		if (m[0] > 0 && m[0] <= 10 && *str[0][--m[0]] && m[1] > 0 && m[1] <= 10 && *str[1][--m[1]] && m[2] > 0 && m[2] <= 10 && *str[2][--m[2]] && m[3] > 0 && m[3] <= 10 && *str[1][--m[3]] && m[4] > 0 && m[4] <= 10 && *str[0][--m[4]])
			printf("%s(%s%s%s)%s\n", str[0][m[0]], str[1][m[1]],
				   str[2][m[2]], str[1][m[3]], str[0][m[4]]);
		else
			puts("Are you kidding me? @\\/@");
	}

	return 0;
}