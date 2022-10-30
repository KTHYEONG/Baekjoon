#include <stdio.h>  // 단어 뒤집기
#include <string.h>

int main()
{
	int t;
	scanf("%d ", &t);

	char str[1001], stack[1001];
	int top = 0;
	for (int i = 0; i < t; i++)
	{
		fgets(str, 1001, stdin);
		for (int j = 0; j < strlen(str) - 1; j++)
		{
			if (str[j] != ' ')
			{
				stack[top++] = str[j];
			}
			if (str[j] == ' ' || j == strlen(str) - 2)
			{
				for (int k = top - 1; k >= 0; k--)
				{
					printf("%c", stack[k]);
				}
				printf(" ");
				top = 0;
			}
		}
		printf("\n");
	}


	return 0;
}