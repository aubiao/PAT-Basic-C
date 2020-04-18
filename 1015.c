#include <stdio.h>

typedef struct Node
{
	long long int number;
	int a, b, total;
} LNode;

void PreDown(LNode data[70000], int i, int n)
{
	int child;
	LNode temp;
	for (temp = data[i]; 2 * i + 1 < n; i = child)
	{
		child = 2 * i + 1;
		if (child != n - 1 &&
			(data[child].total > data[child + 1].total || (data[child].total == data[child + 1].total && data[child].a > data[child + 1].a) || (data[child].total == data[child + 1].total && data[child].a == data[child + 1].a && data[child].number < data[child + 1].number)))
		{
			child++;
		}
		if (temp.total > data[child].total || (temp.total == data[child].total && temp.a > data[child].a) || (temp.total == data[child].total && temp.a == data[child].a && temp.number < data[child].number))
		{
			data[i].number = data[child].number;
			data[i].a = data[child].a;
			data[i].b = data[child].b;
			data[i].total = data[child].total;
		}
		else
		{
			break;
		}
	}
	data[i].number = temp.number;
	data[i].a = temp.a;
	data[i].b = temp.b;
	data[i].total = temp.total;
}

void HeapSort(LNode data[70000], int n)
{
	int i;

	for (i = n / 2; i >= 0; i--)
	{
		PreDown(data, i, n);
	}
	for (i = n - 1; i > 0; i--)
	{
		LNode temp;

		temp.number = data[0].number;
		temp.a = data[0].a;
		temp.b = data[0].b;
		temp.total = data[0].total;
		data[0].number = data[i].number;
		data[0].a = data[i].a;
		data[0].b = data[i].b;
		data[0].total = data[i].total;
		data[i].number = temp.number;
		data[i].a = temp.a;
		data[i].b = temp.b;
		data[i].total = temp.total;
		PreDown(data, 0, i);
	}
}

int main()
{
	int n, p, q, i, j, k, flag, a, b, cnt[4] = {0}, atemp, btemp, totaltemp;
	long long int number, numbertemp;

	scanf("%d %d %d", &n, &p, &q);

	LNode data[4][70000];

	for (i = 0; i < n; i++)
	{
		scanf("%lld %d %d", &number, &a, &b);
		if (a >= q)
		{
			if (b >= q)
			{
				data[0][cnt[0]].number = number;
				data[0][cnt[0]].a = a;
				data[0][cnt[0]].b = b;
				data[0][cnt[0]].total = a + b;
				cnt[0]++;
			}
			else if (b >= p)
			{
				data[1][cnt[1]].number = number;
				data[1][cnt[1]].a = a;
				data[1][cnt[1]].b = b;
				data[1][cnt[1]].total = a + b;
				cnt[1]++;
			}
		}
		else if (a >= p)
		{
			if (b >= p)
			{
				if (a >= b)
				{
					data[2][cnt[2]].number = number;
					data[2][cnt[2]].a = a;
					data[2][cnt[2]].b = b;
					data[2][cnt[2]].total = a + b;
					cnt[2]++;
				}
				else
				{
					data[3][cnt[3]].number = number;
					data[3][cnt[3]].a = a;
					data[3][cnt[3]].b = b;
					data[3][cnt[3]].total = a + b;
					cnt[3]++;
				}
			}
		}
	}

	printf("%d\n", cnt[0] + cnt[1] + cnt[2] + cnt[3]);
	for (i = 0; i < 4; i++)
	{
		//		for(j = 0;j < cnt[i] - 1;j++){
		//			flag = 0;
		//			for(k = cnt[i] - 1;k > j;k--){
		//				if(data[i][k].total > data[i][k-1].total
		//					|| (data[i][k].total == data[i][k-1].total && data[i][k].a > data[i][k-1].a)
		//					|| (data[i][k].total == data[i][k-1].total && data[i][k].a == data[i][k-1].a && data[i][k].number < data[i][k-1].number)){
		//					numbertemp = data[i][k].number;
		//					atemp = data[i][k].a;
		//					btemp = data[i][k].b;
		//					totaltemp = data[i][k].total;
		//					data[i][k].number = data[i][k-1].number;
		//					data[i][k].a = data[i][k-1].a;
		//					data[i][k].b = data[i][k-1].b;
		//					data[i][k].total = data[i][k-1].total;
		//					data[i][k-1].number = numbertemp;
		//					data[i][k-1].a = atemp;
		//					data[i][k-1].b = btemp;
		//					data[i][k-1].total = totaltemp;
		//					flag = 1;
		//				}
		//			}
		//			if(flag == 0){
		//				break;
		//			}
		//		}
		HeapSort(data[i], cnt[i]);
		for (j = 0; j < cnt[i]; j++)
		{
			printf("%lld %d %d\n", data[i][j].number, data[i][j].a, data[i][j].b);
		}
	}

	return 0;
}