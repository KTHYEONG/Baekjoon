#include <stdio.h>  // 2진수 8진수
#include <string.h>

char str[1000010] = { '0', };

int main()
{
	scanf("%s", str);

	int len = strlen(str);
	if (len % 3 == 1)
	{
		printf("%d", str[0] - '0');
	}
	else if (len % 3 == 2)
	{
		printf("%d", (str[0] - '0') * 2 + (str[1] - '0'));
	}

	for (int i = len % 3; i < len; i+=3)
	{
		printf("%d", (str[i] - '0') * 4 + (str[i + 1] - '0') * 2 + (str[i + 2] - '0'));
	}

	return 0;
}