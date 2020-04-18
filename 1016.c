#include <stdio.h>

int main()
{
	int Da, Db;
	long long int A, B, Pa = 0, Pb = 0;

	scanf("%lld %d %lld %d", &A, &Da, &B, &Db);

	while (A != 0)
	{
		if (A % 10 == Da)
		{
			Pa = Pa * 10 + Da;
		}
		A /= 10;
	}

	while (B != 0)
	{
		if (B % 10 == Db)
		{
			Pb = Pb * 10 + Db;
		}
		B /= 10;
	}

	printf("%lld\n", Pa + Pb);

	return 0;
}