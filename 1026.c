#include <stdio.h>
#define CLK_TCK 100

int main()
{
	long long int c1, c2, time;

	scanf("%lld %lld", &c1, &c2);

	c2 -= c1;

	time = c2 / CLK_TCK;
	if (c2 % CLK_TCK >= CLK_TCK / 2)
	{
		time++;
	}

	printf("%02d:%02d:%02d", time / 3600, time % 3600 / 60, time % 60);

	return 0;
}