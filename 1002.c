#include <stdio.h>

int main()
{
	int n = 0, sum = 0, cnt = 0;
	char c;
	char str[][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

	while ((c = getchar()) != '\n')
	{
		n += c - '0';
	}

	while (n != 0)
	{
		sum = sum * 10 + n % 10;
		n /= 10;
		cnt++;
	}

	while (cnt != 0)
	{
		if (sum != 0)
		{
			n = sum % 10;
			sum /= 10;
			printf("%s", str[n]);
		}
		else
		{
			printf("%s", str[0]);
		}
		cnt--;
		if (cnt != 0)
		{
			printf(" ");
		}
		else
		{
			printf("\n");
		}
	}

	return 0;
}