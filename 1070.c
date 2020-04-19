#include <stdio.h>

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void PreDown(int A[], int i, int n)
{
    int child, temp;
    for (temp = A[i]; 2 * i + 1 < n; i = child)
    {
        child = 2 * i + 1;
        if (child < n - 1 && A[child + 1] > A[child])
            child++;
        if (temp < A[child])
            A[i] = A[child];
        else
            break;
    }
    A[i] = temp;
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
    int n, A[10000], i;
    double sum = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    HeapSort(A, n);

    sum = A[0];
    for (i = 1; i < n; i++)
    {
        sum = (sum + A[i]) / 2;
    }

    printf("%d\n", (int)sum);

    return 0;
}