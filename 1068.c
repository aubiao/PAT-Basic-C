#include <stdio.h>
#include <math.h>

int B[100000000] = {0};

int main()
{
    int m, n, tol, i, j, A[1000][1000], cnt = 0, x, y, a;

    scanf("%d %d %d", &m, &n, &tol);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &A[i][j]);
            B[A[i][j]]++;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (B[A[i][j]] == 1)
            {
                if (fabs(A[i][j] - A[i][j - 1]) > tol && fabs(A[i][j] - A[i][j + 1]) > tol && fabs(A[i][j] - A[i - 1][j - 1]) > tol && fabs(A[i][j] - A[i - 1][j]) > tol && fabs(A[i][j] - A[i - 1][j + 1]) > tol && fabs(A[i][j] - A[i + 1][j - 1]) > tol && fabs(A[i][j] - A[i + 1][j]) > tol && fabs(A[i][j] - A[i + 1][j + 1]) > tol)
                {
                    cnt++;
                    if (cnt > 1)
                    {
                        printf("Not Unique\n");
                        return 0;
                    }
                    else
                    {
                        x = j + 1;
                        y = i + 1;
                        a = A[i][j];
                    }
                }
            }
        }
    }

    if (cnt == 1)
    {
        printf("(%d, %d): %d\n", x, y, a);
    }
    else
    {
        printf("Not Exist\n");
    }

    return 0;
}