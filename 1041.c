#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char str[18];
	int number;
} LNode;

int main()
{
	int i, n, m, p, q;
	char str[18];

	scanf("%d", &n);

	LNode *exam = (LNode *)malloc((n + 1) * sizeof(LNode));

	for (i = 0; i < n; i++)
	{
		scanf("%s %d %d", str, &p, &q);
		exam[p].number = q;
		strcpy(exam[p].str, str);
	}

	scanf("%d", &m);

	for (i = 0; i < m; i++)
	{
		scanf("%d", &p);
		printf("%s %d\n", exam[p].str, exam[p].number);
	}

	return 0;
}