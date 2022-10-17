#include <stdio.h>  // 크로아티아 알파벳
#include <string.h>

int main()
{
	char str[101];
	scanf("%s", str);

	int count = strlen(str);
	for (int i = 0; i < strlen(str); i++)                   // 전체 길이 - 크로아티아 알파벳(크로아티아 알파벳 조합을 한개로 취급)
	{
		if (str[i] == '=')
		{
			if (str[i - 1] == 'c' || str[i - 1] == 's')
				count--;
			if (str[i - 1] == 'z')
			{
				count--;
				if (str[i - 2] == 'd')
					count--;
			}
		}
		if (str[i] == '-')
		{
			if (str[i - 1] == 'c' || str[i - 1] == 'd')
				count--;
		}

		if (str[i] == 'j')
		{
			if (str[i - 1] == 'l' || str[i - 1] == 'n')
				count--;
		}

	}

	printf("%d", count);

	return 0;
}