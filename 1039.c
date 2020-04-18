#include <stdio.h>

int translate(char c)
{
	int a;

	if (c >= '0' && c <= '9')
	{
		a = c - '0';
	}
	else if (c >= 'A' && c <= 'Z')
	{
		a = c - 'A' + 10;
	}
	else
	{
		a = c - 'a' + 36;
	}

	return a;
}

int main()
{
	int i, a, A[62] = {0}, cnt = 0, sum = 0;
	char str[1001];

	scanf("%s", str);

	for (i = 0; str[i] != '\0'; i++)
	{
		sum++;
		a = translate(str[i]);
		A[a]++;
	}

	scanf("%s", str);

	for (i = 0; str[i] != '\0'; i++)
	{
		a = translate(str[i]);
		if (A[a] == 0)
		{
			cnt++;
		}
		else
		{
			A[a]--;
		}
	}

	if (cnt == 0)
	{
		printf("Yes %d", sum - i);
	}
	else
	{
		printf("No %d", cnt);
	}

	return 0;
}