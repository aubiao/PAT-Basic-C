#include <stdio.h>

int main()
{
	long long int sum = 0;
	int i = 0, cntp = 0, cntt = 0;
	char str[100001], c;

	while ((c = getchar()) != '\n')
	{
		str[i++] = c;
		if (c == 'T')
		{
			cntt++;
		}
	}

	str[i] = '\0';

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == 'P')
		{
			cntp++;
		}
		else if (str[i] == 'T')
		{
			cntt--;
		}
		else if (str[i] == 'A')
		{
			sum += cntp * cntt;
		}
	}

	printf("%lld", sum % 1000000007);

	return 0;
}