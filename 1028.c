#include <stdio.h>

void copyname(char name1[], char name2[])
{
	int i = 0;

	while (name2[i] != '\0')
	{
		name1[i] = name2[i];
		i++;
	}
	name1[i] = '\0';
}

int main()
{
	int n, i, year, month, day, cnt = 0;
	long long int max = 20140907, min = 18140905, birth;
	char name[6], maxname[6], minname[6];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%s %d/%d/%d", name, &year, &month, &day);
		birth = year * 10000 + month * 100 + day;
		if (birth >= 18140906 && birth <= 20140906)
		{
			cnt++;
			if (max > birth)
			{
				copyname(maxname, name);
				max = birth;
			}
			if (min < birth)
			{
				copyname(minname, name);
				min = birth;
			}
		}
	}

	if (cnt == 0)
	{
		printf("0");
	}
	else
	{
		printf("%d %s %s\n", cnt, maxname, minname);
	}

	return 0;
}