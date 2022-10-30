/* #include <stdio.h>  // ¾ËÆÄºª Ã£±â
#include <string.h>

int main()
{
	char str[100];
	scanf("%s", str);

	int arr[26], length = strlen(str);

	for (int i = 0; i < 26; i++)
	{
		arr[i] = -1;
	}

	for (int i = 97; i <= 122; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (str[j] == i)
			{
				arr[str[j] - 'a'] = j;
				break;
			}
		}
	}

	for (int i = 0; i < 26; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
} */

#include <stdio.h>
#include <string.h>

int main()
{
	char str[101];
	scanf("%s", str);

	int arr[26];
	for (int i = 0; i < 26; i++)
		arr[i] = -1;

	for (int i = 97; i < 123; i++)
	{
		for (int j = 0; j < strlen(str); j++)
		{
			if (str[j] == i)
			{
				arr[str[j] - 'a'] = j;
				break;
			}
		}
	}

	for (int i = 0; i < 26; i++)
		printf("%d ", arr[i]);

	return 0;
}