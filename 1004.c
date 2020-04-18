#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
	char name[11];
	char number[11];
	int score;
} Node, *PNode;

void cmp(char *str, char *name)
{
	int i = 0;

	while (name[i] != '\0')
	{
		str[i] = name[i];
		i++;
	}
	str[i] = '\0';
}

int main()
{
	int n, i, score;
	char name[11], number[11];

	scanf("%d", &n);

	PNode record = (PNode)malloc(2 * sizeof(Node));
	record[0].score = 0;
	record[1].score = 0;

	for (i = 0; i < n; i++)
	{
		scanf("%s %s %d", name, number, &score);
		if (i > 0)
		{
			if (score > record[0].score)
			{
				cmp(&record[0].name, name);
				cmp(&record[0].number, number);
				record[0].score = score;
			}
			if (score < record[1].score)
			{
				cmp(&record[1].name, name);
				cmp(&record[1].number, number);
				record[1].score = score;
			}
		}
		else if (i == 0)
		{
			cmp(&record[0].name, name);
			cmp(&record[0].number, number);
			record[0].score = score;
			cmp(&record[1].name, name);
			cmp(&record[1].number, number);
			record[1].score = score;
		}
	}
	printf("%s %s\n", record[0].name, record[0].number);
	printf("%s %s\n", record[1].name, record[1].number);

	return 0;
}