#include <stdio.h>

int main()
{
	int pg, ps, pk, ag, as, ak, p, a, temp;

	scanf("%d.%d.%d %d.%d.%d", &pg, &ps, &pk, &ag, &as, &ak);

	// 17s = g,29k = s
	p = pg * 17 * 29 + 29 * ps + pk;
	a = ag * 17 * 29 + 29 * as + ak;

	a -= p;

	if (a < 0)
	{
		printf("-");
		a *= -1;
	}
	temp = a / (17 * 29);

	printf("%d.%d.%d", temp, (a - temp * 17 * 29) / 29, a % 29);

	return 0;
}