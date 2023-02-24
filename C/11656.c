#include <stdio.h>  // 접미사 배열
#include <stdlib.h>
#include <string.h>

char str1[1001];
char str2[1001][1001];
char temp[1001];

int main()
{
	scanf("%s", str1);
	for (int i = 0; i < strlen(str1); i++)
	{
		for (int j = i; j < strlen(str1); j++)
		{
			str2[i][j - i] = str1[j];
		}
	}

	for (int i = 0; i < strlen(str1) - 1; i++)
	{
		for (int j = 0; j < strlen(str1) - 1 - i; j++)
		{
			if (strcmp(str2[j], str2[j + 1]) > 0)
			{
				strcpy(temp, str2[j]);
				strcpy(str2[j], str2[j + 1]);
				strcpy(str2[j + 1], temp);
			}
		}
	}

	for (int i = 0; i < strlen(str1); i++)
		printf("%s\n", str2[i]);


	return 0;
}