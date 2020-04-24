#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char school[7];
    int score;
    int number;
} pat, *Pat;

typedef struct
{
    char id[7], school[7];
    int score;
} student, *Student;

void chardown(char *school)
{
    int i;
    for (i = 0; school[i] != '\0'; i++)
    {
        if (school[i] >= 'A' && school[i] <= 'Z')
        {
            school[i] = school[i] - 'A' + 'a';
        }
    }
}

int cmp_school(const void *a, const void *b)
{
    Student s1 = *(Student *)a;
    Student s2 = *(Student *)b;
    return strcmp(s1->school, s2->school);
}

int cmp(const void *a, const void *b)
{
    Pat s1 = *(Pat *)a;
    Pat s2 = *(Pat *)b;

    if (s1->score != s2->score)
    {
        return s2->score - s1->score;
    }
    else if (s1->number != s2->number)
    {
        return s1->number - s2->number;
    }
    return strcmp(s1->school, s2->school);
}

int main()
{
    int n, i, j, score, cnt = 0;
    char id[7], school[7];
    double total_score = 0;

    scanf("%d", &n);

    pat *p = (pat *)malloc(n * sizeof(pat));
    Pat *pp = (Pat *)malloc(n * sizeof(Pat)), ppp = p;
    student *s = (student *)malloc(n * sizeof(student));
    Student *sp = (Student *)malloc(n * sizeof(Student)), spp = s;

    for (i = 0; i < n; i++)
    {
        spp = s + i;
        scanf("%s %d %s", spp->id, &spp->score, spp->school);
        chardown(spp->school);
        sp[i] = spp;
    }
    qsort(sp, n, sizeof(Student), cmp_school);
    strcpy(ppp->school, sp[0]->school);
    switch (sp[0]->id[0])
    {
    case 'A':
        total_score = sp[0]->score;
        break;
    case 'T':
        total_score = sp[0]->score * 1.5;
        break;
    case 'B':
        total_score = sp[0]->score / 1.5;
        break;
    }
    ppp->number = 1;
    pp[cnt] = ppp;
    cnt++;

    for (i = 1; i < n; i++)
    {
        if (strcmp(sp[i]->school, sp[i - 1]->school) != 0)
        {
            ppp->score = (int)total_score;
            ppp = &p[cnt];
            strcpy(ppp->school, sp[i]->school);
            ppp->number = 0;
            total_score = 0;
            pp[cnt] = ppp;
            cnt++;
        }
        switch (sp[i]->id[0])
        {
        case 'A':
            total_score += sp[i]->score;
            break;
        case 'T':
            total_score += sp[i]->score * 1.5;
            break;
        case 'B':
            total_score += sp[i]->score / 1.5;
            break;
        }
        ppp->number++;
    }
    ppp->score = (int)total_score;

    qsort(pp, cnt, sizeof(Pat), cmp);

    printf("%d\n", cnt);
    j = 0;
    for (i = 0; i < cnt; i++)
    {
        if (i != 0 && pp[i - 1]->score == pp[i]->score)
        {
            j = j;
        }
        else
        {
            j = i + 1;
        }
        printf("%d %s %d %d\n", j, pp[i]->school, pp[i]->score, pp[i]->number);
    }

    return 0;
}