#include <stdio.h>  // ¾ËÆÄºª °³¼ö
#include <string.h>

int main()
{
	char str[101];
	scanf("%s", str);

	int arr[26] = { 0, };
	for (int i = 0; i < strlen(str); i++)
	{
		arr[str[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
		printf("%d ", arr[i]);

	return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str[101];
	scanf("%s", str);

	int len = strlen(str), arr[26] = { 0, };
	for (int i = 0; i < len; i++)
	{
		for (char j = 'A'; j <= 'Z'; j++)
		{
			if (str[i] == j)
				arr[str[i] - 'A']++;
		}

		for (char j = 'a'; j <= 'z'; j++)
		{
			if (str[i] == j)
				arr[str[i] - 'a']++;
		}
	}

	for (int i = 0; i < 26; i++)
		printf("%d ", arr[i]);

	return 0;
}
*/