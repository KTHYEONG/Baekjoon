#include <stdio.h>  // 8진수 2진수
#include <string.h>

char str[333335];

int main()
{
	scanf("%s", str);

	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '0')
		{
			if (i == 0)
				printf("0");
			else
				printf("000");
		}
		else if (str[i] == '1')
		{
			if (i == 0)
				printf("1");
			else
				printf("001");
		}
		else if (str[i] == '2')
		{
			if (i == 0)
				printf("10");
			else
				printf("010");
		}
		else if (str[i] == '3')
		{
			if (i == 0)
				printf("11");
			else
				printf("011");
		}
		else if (str[i] == '4')
			printf("100");
		else if (str[i] == '5')
			printf("101");
		else if (str[i] == '6')
			printf("110");
		else if (str[i] == '7')
			printf("111");
	}

	return 0;
}