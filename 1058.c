#include <stdio.h>
typedef struct
{
	int a;
	int b;
	int c;
	char str[5];
} LNode;
int main()
{
	int n, m, i, j, sum, A[101] = {0}, p, B[1001] = {0}, flag, max;
	LNode L[101];
	char c, d;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &L[i].a, &L[i].b, &L[i].c);
		for (j = 0; j < L[i].c; j++)
		{
			getchar();
			scanf("%c", &L[i].str[j]);
		}
	}
	getchar();
	for (i = 0; i < n; i++)
	{
		p = 0;
		while ((c = getchar()) != '\n')
		{
			if (c == ')')
			{
				p++;
			}
			else if (c != '(' && c >= '0' && c <= '9')
			{
				flag = 0;
				for (j = 0; j < c - '0'; j++)
				{
					if (L[p].c == c - '0')
					{
						getchar();
						scanf("%c", &d);
						if (d != L[p].str[j])
						{
							flag = 1;
						}
					}
					else
					{
						flag = 1;
						break;
					}
				}
				if (flag == 1)
				{
					A[p]++;
				}
				else
				{
					B[i] += L[p].a;
				}
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d\n", B[i]);
	}
	max = A[0];
	for (i = 0; i < p; i++)
	{
		if (max < A[i])
		{
			max = A[i];
		}
	}
	if (max == 0)
	{
		printf("Too simple\n");
	}
	else
	{
		printf("%d", max);
		for (i = 0; i < p; i++)
		{
			if (A[i] == max)
			{
				printf(" %d", i + 1);
			}
		}
	}
	return 0;
}