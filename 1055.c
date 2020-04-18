#include <stdio.h>
#include <string.h>

typedef struct student
{
	char name[9];
	int height;
} student, *Student;

int cmp(const void *a, const void *b)
{
	Student s1 = *(Student *)a;
	Student s2 = *(Student *)b;
	if (s1->height != s2->height)
	{
		return s2->height - s1->height;
	}
	return strcmp(s1->name, s2->name);
}

Student *printrow(Student *s, int num)
{
	int i;
	for (i = num / 2 * 2 - 1; i > 0; i -= 2)
		printf("%s ", s[i]->name);
	for (i = 0; i < num; i += 2)
		printf("%s%c", s[i]->name, i + 2 < num ? ' ' : '\n');
	return s + num;
}

int main()
{
	int i, N, K;
	student students[10000] = {0};
	Student sp[10000] = {0}, *p = sp;

	scanf("%d %d", &N, &K);

	for (i = 0; i < N; i++)
	{
		sp[i] = students + i;
		scanf("%s %d", sp[i]->name, &sp[i]->height);
	}

	qsort(sp, N, sizeof(Student), cmp);

	p = printrow(p, N - N / K * (K - 1));
	while (p < sp + N)
		p = printrow(p, N / K);

	return 0;
}