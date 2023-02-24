#include <stdio.h>  // ROT13
#include <string.h>

int main()
{
	char str[102];
	fgets(str, 102, stdin);

	for (int i = 0; i < strlen(str); i++)
	{
		if ((str[i] >= 'A' && str[i] <= 'M') || (str[i] >= 'a' && str[i] <= 'm'))
		{
			printf("%c", str[i] + 13);
		}
		else if ((str[i] >= 'N' && str[i] <= 'Z') || (str[i] >= 'n' && str[i] <= 'z'))
		{
			printf("%c", str[i] - 13);
		}
		else
		{
			printf("%c", str[i]);
		}
	}

	return 0;
}