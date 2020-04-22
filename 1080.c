#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char name[21];
    int gp;
    int gm;
    int gf;
    int g;
} student, *Student;

int cmp_name(const void *a, const void *b)
{
    Student s1 = *(Student *)a;
    Student s2 = *(Student *)b;
    return strcmp(s1->name, s2->name);
}

int cmp(const void *a, const void *b)
{
    Student s1 = *(Student *)a;
    Student s2 = *(Student *)b;
    if (s2->g != s1->g)
        return s2->g - s1->g;
    return strcmp(s1->name, s2->name);
}

// void Swap(Student *a, Student *b)
// {
//     Student temp;
//     temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void PreDown(Student *sp, int i, int n)
// {
//     int child;
//     Student temp;
//     for (temp = sp[i]; 2 * i + 1 < n; i = child)
//     {
//         child = 2 * i + 1;
//         if (child < n - 1 && (sp[child]->g > sp[child + 1]->g || (sp[child]->g == sp[child + 1]->g && strcmp(sp[child]->name, sp[child + 1]->name) < 0)))
//             child++;
//         if (temp->g > sp[child]->g || (temp->g == sp[child]->g && strcmp(temp->name, sp[child]->name) < 0))
//         {
//             sp[i] = sp[child];
//         }
//         else
//         {
//             break;
//         }
//     }
//     sp[i] = temp;
// }

// void HeapSort(Student *sp, int n)
// {
//     int i;
//     for (i = n / 2; i >= 0; i--)
//     {
//         PreDown(sp, i, n);
//     }
//     for (i = n - 1; i > 0; i--)
//     {
//         Swap(&sp[0], &sp[i]);
//         PreDown(sp, 0, i);
//     }
// }

int main()
{
    int p, m, n, i, j, g, cnt = 0, low, high, mid;
    char name[21];

    scanf("%d %d %d", &p, &m, &n);

    student *S = (student *)malloc(p * sizeof(student));
    Student *sp = (Student *)malloc(p * sizeof(Student)), ps = S;

    for (i = 0; i < p; i++)
    {
        scanf("%s %d", name, &g);
        if (g >= 200)
        {
            strcpy(ps->name, name);
            ps->gp = g;
            ps->gm = -1;
            ps->gf = -1;
            ps->g = -1;
            sp[cnt++] = ps++;
        }
    }

    qsort(sp, cnt, sizeof(Student), cmp_name);

    for (i = 0; i < m; i++)
    {
        scanf("%s %d", name, &g);

        low = 0;
        high = cnt - 1;

        while (low <= high)
        {
            mid = (low + high) / 2;
            ps = sp[mid];
            j = strcmp(name, ps->name);
            if (j == 0)
            {
                ps->gm = g;
                break;
            }
            else if (j > 0)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        scanf("%s %d", name, &g);

        low = 0;
        high = cnt - 1;

        while (low <= high)
        {
            mid = (low + high) / 2;
            ps = sp[mid];
            j = strcmp(name, ps->name);
            if (j == 0)
            {
                ps->gf = g;
                if (g >= ps->gm)
                {
                    ps->g = g;
                }
                else
                {
                    ps->g = (int)(ps->gm * 0.4 + g * 0.6 + 0.5);
                }
                break;
            }
            else if (j > 0)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    qsort(sp, cnt, sizeof(Student), cmp);
    // HeapSort(sp, cnt);

    for (i = 0; i < cnt && sp[i]->g >= 60; i++)
    {
        printf("%s %d %d %d %d\n", sp[i]->name, sp[i]->gp, sp[i]->gm, sp[i]->gf, sp[i]->g);
    }

    return 0;
}