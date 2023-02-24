#include <stdio.h>  // OXÄûÁî

int main()
{
	int n;
	char str[80];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int j = 0, k = 1, count = 0;
		scanf("%s", str);
		while (str[j] != '\0')
		{
			if (str[j] == 'O')
			{
				count += k;
				k++;
			}
			else
			{
				k = 1;
			}
			j++;
		}
		printf("%d\n", count);
	}

	return 0;
}