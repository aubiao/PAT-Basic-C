#include <stdio.h>

void swap(char *str, int low, int high)
{
	char temp;
	while (low < high)
	{
		temp = str[low];
		str[low] = str[high];
		str[high] = temp;
		low++;
		high--;
	}
}

int main()
{
	int i = 0, j = 0;
	char str[81], c;

	gets(str);

	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			swap(str, j, i - 1);
			j = i + 1;
		}
		i++;
	}
	swap(str, j, i - 1);
	swap(str, 0, i - 1);

	printf("%s", str);

	return 0;
}