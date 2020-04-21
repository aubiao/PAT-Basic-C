#include <stdio.h>

int main()
{
    int firstaddr, n, k, A[100000][2] = {0}, i, addr, maddr = -1, baddr = -1, flag = 0;

    scanf("%d %d %d", &firstaddr, &n, &k);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &addr);
        scanf("%d %d", &A[addr][0], &A[addr][1]);
    }

    addr = firstaddr;

    while (A[addr][1] != -1)
    {
        if (A[addr][0] < 0)
        {
            if (flag != 0)
            {
                printf(" %05d\n", addr);
            }
            printf("%05d %d", addr, A[addr][0]);
            flag = 1;
        }
        else if (A[addr][0] >= 0 && A[addr][0] <= k && maddr == -1)
        {
            maddr = addr;
        }
        else if (A[addr][0] > k && baddr == -1)
        {
            baddr = addr;
        }
        addr = A[addr][1];
    }

    if (A[addr][0] < 0)
    {
        if (flag != 0)
        {
            printf(" %05d\n", addr);
        }
        printf("%05d %d", addr, A[addr][0]);
        flag = 1;
    }

    if (maddr == -1)
    {
        maddr = addr;
    }
    addr = maddr;

    while (A[addr][1] != -1)
    {
        if (A[addr][0] >= 0 && A[addr][0] <= k)
        {
            if (flag != 0)
            {
                printf(" %05d\n", addr);
            }
            printf("%05d %d", addr, A[addr][0]);
            flag = 1;
        }
        else if (A[addr][0] > k && baddr == -1)
        {
            baddr = addr;
        }
        addr = A[addr][1];
    }

    if (A[addr][0] >= 0 && A[addr][0] <= k)
    {
        if (flag != 0)
        {
            printf(" %05d\n", addr);
        }
        printf("%05d %d", addr, A[addr][0]);
        flag = 1;
    }

    if (baddr == -1)
    {
        baddr = addr;
    }
    addr = baddr;

    while (A[addr][1] != -1)
    {
        if (A[addr][0] > k)
        {
            if (flag != 0)
            {
                printf(" %05d\n", addr);
            }
            printf("%05d %d", addr, A[addr][0]);
            flag = 1;
        }
        addr = A[addr][1];
    }

    if (A[addr][0] > k)
    {
        if (flag != 0)
        {
            printf(" %05d\n", addr);
        }
        printf("%05d %d", addr, A[addr][0]);
    }

    printf(" -1\n");

    return 0;
}