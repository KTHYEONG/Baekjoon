/* #include <stdio.h>  // ³ª¸ÓÁö

int main()
{
	unsigned int arr[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
		arr[i] %= 42;
	}

	int result = 0;
	for (int i = 0; i < 10; i++)
	{
		int count = 0;
		for (int j = i + 1; j < 10; j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}
		}
		if (count == 0)
		{
			result++;
		}
	}

	printf("%d", result);

	return 0;
} */

#include <stdio.h>

int main()
{
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
		arr[i] %= 42;
	}

	int result = 0;
	for (int i = 0; i < 10; i++)
	{
		int count = 0;
		for (int j = i + 1; j < 10; j++)
		{
			if (arr[i] == arr[j])
				count++;
		}
		if (count == 0)
			result++;
	}

	printf("%d", result);

	return 0;
}