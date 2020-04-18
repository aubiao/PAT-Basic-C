#include <stdio.h>

int main()
{
	char str1[81], str2[81], c;
	int A[37] = {0}, i = 0, j = 0, k;

	scanf("%s", str1);
	scanf("%s", str2);

	while (str1[i] != '\0')
	{
		if (str1[i] != str2[j])
		{
			c = str1[i];
			if (str1[i] >= '0' && str1[i] <= '9')
			{
				k = str1[i] - '0';
				A[k]++;
			}
			else if (str1[i] >= 'A' && str1[i] <= 'Z')
			{
				k = str1[i] - 'A' + 10;
				A[k]++;
			}
			else if (str1[i] >= 'a' && str1[i] <= 'z')
			{
				k = str1[i] - 'a' + 10;
				c = str1[i] - 'a' + 'A';
				A[k]++;
			}
			else
			{
				k = 36;
				A[36]++;
			}
			if (A[k] == 1)
			{
				printf("%c", c);
			}
			i++;
		}
		else
		{
			i++;
			j++;
		}
	}

	return 0;
}