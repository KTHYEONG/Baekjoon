#include <stdio.h>  // 단어 공부
#include <string.h>

int arr[26];
char str[1000000];

int main()
{
	scanf("%s", str);
	int length = strlen(str);

	for (int i = 0; i < length; i++)        // a ~ Z 까지 몇개 존재하는지 검사하기
	{
		if (str[i] >= 'a')
		{
			arr[str[i] - 'a']++;
		}
		else
		{
			arr[str[i] - 'A']++;
		}
	}

	int max = 0; char result;                    // 제일 많이 나온 알파벳 찾기     
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] == max)
		{
			result = '?';
		}
		else if (arr[i] > max)
		{
			max = arr[i];
			result = 'A' + i;
		}
	}

	printf("%c", result);

	return 0;
}