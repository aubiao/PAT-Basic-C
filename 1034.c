#include <stdio.h>

long gcd(long a, long b)
{
	long p, q, t;
	p = a;
	q = b;
	while (q > 0)
	{
		t = p % q;
		p = q;
		q = t;
	}

	return p;
}

void PrintNum(long a, long b)
{
	int flag = 1;
	long temp = a, p;

	if (temp < 0)
	{
		printf("(-");
		a *= -1;
		flag = -1;
	}

	if (a >= b && a != 0)
	{
		printf("%ld", a / b);
		a %= b;
	}

	if (temp == 0)
	{
		printf("0");
	}
	else if (a != 0)
	{
		if (temp * flag >= b)
		{
			printf(" ");
		}
		p = gcd(a, b);

		if (p != 1)
		{
			a = a / p;
			b = b / p;
		}

		printf("%ld/%ld", a, b);
	}

	if (temp < 0)
	{
		printf(")");
	}
}

void PrintRight(long a, long b, long c, long d, char m)
{
	int p;

	if (b == 0 || d == 0 || (m == '/' && c == 0))
	{
		printf("Inf");
	}
	else
	{
		if (m == '+')
		{
			a *= d;
			c *= b;
			b = b * d;
			a += c;
		}
		else if (m == '-')
		{
			a *= d;
			c *= b;
			b = b * d;
			a -= c;
		}
		else if (m == '*')
		{
			a *= c;
			b *= d;
		}
		else if (m == '/')
		{
			a *= d;
			b *= c;
			if (b < 0)
			{
				a *= -1;
				b *= -1;
			}
		}
		PrintNum(a, b);
	}
}

void PrintLeft(long a, long b, long c, long d, char m)
{
	PrintNum(a, b);
	printf(" %c ", m);
	PrintNum(c, d);
	printf(" = ");
}

int main()
{
	long a, b, c, d;

	scanf("%ld/%ld %ld/%ld", &a, &b, &c, &d);

	// +
	PrintLeft(a, b, c, d, '+');
	PrintRight(a, b, c, d, '+');
	printf("\n");

	// -
	PrintLeft(a, b, c, d, '-');
	PrintRight(a, b, c, d, '-');
	printf("\n");

	// *
	PrintLeft(a, b, c, d, '*');
	PrintRight(a, b, c, d, '*');
	printf("\n");

	// /
	PrintLeft(a, b, c, d, '/');
	PrintRight(a, b, c, d, '/');
	printf("\n");

	return 0;
}