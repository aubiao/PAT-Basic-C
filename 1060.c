#include <stdio.h>

void PreDown(int A[], int i, int n)
{
    int child, temp;

    for (temp = A[i]; i * 2 + 1 < n; i = child)
    {
        child = i * 2 + 1;
        if (child < n - 1 && A[child + 1] > A[child])
            child++;
        if (temp < A[child])
            A[i] = A[child];
        else
            break;
    }

    A[i] = temp;
}

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void HeapSort(int A[], int n)
{
    int i;

    for (i = n / 2; i >= 0; i--)
    {
        PreDown(A, i, n);
    }

    for (i = n - 1; i > 0; i--)
    {
        Swap(&A[0], &A[i]);
        PreDown(A, 0, i);
    }
}

int main()
{
    int n, A[100000], i, cnt, max;

    scanf("%d", &n);

    cnt = n;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    HeapSort(A, n);

    for (i = 0; i < n; i++)
    {
        max = A[i];
        if (cnt < max)
        {
            break;
        }
        cnt--;
    }

    printf("%d", cnt);

    return 0;
}