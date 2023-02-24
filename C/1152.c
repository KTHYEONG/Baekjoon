#include <stdio.h>  // 단어의 개수
#include <string.h>

char str[1000001];

int main()
{
	scanf("%[^\n]s", str);        // 공백 포함 문자열 입력받기

	int count = 0;
	if (str[0] != ' ')			  // 첫 글자가 공백이 아닌 경우
		count++;

	for (int i = 1; i < strlen(str); i++)
	{
		if (str[i - 1] == ' ' && str[i] != ' ')
		{
			count++;
		}
	}

	printf("%d", count);

	return 0;
}