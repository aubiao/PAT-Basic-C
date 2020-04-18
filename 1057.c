#include <stdio.h>

int main()
{
	int cnt0 = 0, cnt1 = 0, sum = 0;
	char c;

	while ((c = getchar()) != '\n')
	{
		if (c >= 'A' && c <= 'Z')
		{
			sum += c - 'A' + 1;
		}
		else if (c >= 'a' && c <= 'z')
		{
			sum += c - 'a' + 1;
		}
	}

	while (sum)
	{
		if (sum % 2 == 1)
		{
			cnt1++;
		}
		else
		{
			cnt0++;
		}
		sum /= 2;
	}

	printf("%d %d", cnt0, cnt1);

	return 0;
}