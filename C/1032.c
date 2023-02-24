#include <stdio.h>  // 명령 프롬프트
#include <stdlib.h>
#include <string.h>


int main()
{
	int n;
	scanf("%d", &n);

	char** str;
	str = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++)
	{
		*(str + i) = (char*)malloc(sizeof(char) * 51);
		scanf("%s", *(str + i));
	}

	if (n == 1)
		printf("%s", str[0]);
	else
	{
		int len = strlen(str[0]);
		char answer[51] = { NULL };
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < len; j++)
			{
				if (str[0][j] != str[i][j])
					answer[j] = '?';
				else if (answer[j] != '?')
					answer[j] = str[0][j];
			}
		}
		printf("%s", answer);
	}
	

	return 0;
}