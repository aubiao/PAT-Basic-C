#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char number[14];
    char level[2];
    int room;
    int birthday;
    int id;
    int score;
} student, *Student;

int cmp(const void *a, const void *b)
{
    Student s1 = *(Student *)a;
    Student s2 = *(Student *)b;

    if (s1->score != s2->score)
    {
        return s2->score - s1->score;
    }
    return strcmp(s1->number, s2->number);
}

int main()
{
    int n, m, i, j, k, type, flag, room, sum, cnt, birthday;
    student s[10000];
    Student ps[10000] = {0}, pps = s;
    char c;

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++)
    {
        pps = &s[i];
        scanf("%s %d", pps->number, &pps->score);
        sscanf(pps->number, "%1s%3d%6d%d3d", pps->level, &pps->room, &pps->birthday, &pps->id);
        ps[i] = pps;
    }

    qsort(ps, n, sizeof(Student), cmp);

    for (i = 0; i < m; i++)
    {
        scanf("%d", &type);
        flag = 0;
        if (type == 1)
        {
            scanf(" %c", &c);
            printf("Case %d: %d %c\n", i + 1, type, c);
            for (j = 0; j < n; j++)
            {
                if (ps[j]->number[0] == c)
                {
                    printf("%s %d\n", ps[j]->number, ps[j]->score);
                    flag = 1;
                }
            }
        }
        else if (type == 2)
        {
            scanf(" %d", &room);
            printf("Case %d: %d %d\n", i + 1, type, room);
            cnt = 0;
            sum = 0;
            for (j = 0; j < n; j++)
            {
                if (ps[j]->room == room)
                {
                    sum += ps[j]->score;
                    cnt++;
                    flag = 1;
                }
            }
            if (flag == 1)
            {
                printf("%d %d\n", cnt, sum);
            }
        }
        else
        {
            scanf(" %d", &birthday);
            printf("Case %d: %d %06d\n", i + 1, type, birthday);
            int rooms[1000] = {0}, max = 0;
            for (j = 0; j < n; j++)
            {
                if (ps[j]->birthday == birthday)
                {
                    rooms[ps[j]->room]++;
                    flag = 1;
                    if (rooms[ps[j]->room] > max)
                    {
                        max = rooms[ps[j]->room];
                    }
                }
            }
            for (j = max; j > 0; j--)
            {
                for (k = 101; k < 1000; k++)
                {
                    if (rooms[k] == j)
                    {
                        printf("%d %d\n", k, j);
                    }
                }
            }
        }
        if (flag == 0)
        {
            printf("NA\n");
        }
    }

    return 0;
}