#include <stdio.h>

int main()
{
	int n, i, j, A[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2}, flag = 0, sum;
	char str[20], B[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%s", str);
		sum = 0;
		for (j = 0; j < 17; j++)
		{
			if (str[j] >= '0' && str[j] <= '9')
			{
				sum += A[j] * (str[j] - '0');
			}
			else
			{
				printf("%s\n", str);
				flag = 1;
				sum = 0;
				break;
			}
		}
		if (B[sum % 11] != str[17] && sum != 0)
		{
			printf("%s\n", str);
			flag = 1;
		}
	}

	if (flag == 0)
	{
		printf("All passed\n");
	}

	return 0;
}