#include <stdio.h>
typedef struct
{
	int address;
	int data;
	int next;
} LNode;
void swap(LNode *a, LNode *b)
{
	LNode temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void swaparr(LNode L[], int low, int high)
{
	LNode temp;
	while (low < high)
	{
		temp = L[low];
		L[low] = L[high];
		L[high] = temp;
		high--;
		low++;
	}
}
int main()
{
	int first, n, k, i, j = 0;
	scanf("%d %d %d", &first, &n, &k);
	LNode L[n];
	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d", &L[i].address, &L[i].data, &L[i].next);
	}
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if (L[j].address == (i ? L[i - 1].next : first))
			{
				swap(&L[i], &L[j]);
				break;
			}
		}
		if (L[i].next == -1)
		{
			n = i + 1;
			break;
		}
	}
	for (i = 0; i < n / k; i++)
	{
		swaparr(L, i * k, i * k + k - 1);
	}
	for (i = 0; i < n - 1; i++)
	{
		printf("%05d %d %05d\n", L[i].address, L[i].data, L[i + 1].address);
	}
	printf("%05d %d -1", L[i].address, L[i].data);
	return 0;
}