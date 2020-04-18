#include <stdio.h>

int str2num(char c)
{
	int a = 0;
	if (c >= '0' && c <= '9')
	{
		a = c - '0';
	}
	else if (c >= 'A' && c <= 'Z')
	{
		a = c - 'A' + 10;
	}
	else if (c >= 'a' && c <= 'z')
	{
		a = c - 'a' + 10;
	}
	else if (c == '_')
	{
		a = 36;
	}
	else if (c == ',')
	{
		a = 37;
	}
	else if (c == '.')
	{
		a = 38;
	}
	else if (c == '-')
	{
		a = 39;
	}
	else if (c == '+')
	{
		a = 40;
	}
	return a;
}

int main()
{
	char str[100001], c;
	int A[70] = {0}, m, i;

	while ((c = getchar()) != '\n')
	{
		m = str2num(c);
		A[m] = 1;
	}

	scanf("%s", str);

	for (i = 0; str[i] != '\0'; i++)
	{
		m = str2num(str[i]);
		if (A[m] == 1 || (str[i] >= 'A' && str[i] <= 'Z' && A[40] == 1))
		{
			continue;
		}
		printf("%c", str[i]);
	}

	return 0;
}