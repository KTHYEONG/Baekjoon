#include <stdio.h>  // °ñµå¹ÙÈå ÆÄÆ¼¼Ç

int arr[1000001] = { 0, };

int main()
{
	for (int i = 2; i < 1000001; i++)
	{
		if (arr[i] == 1)
			continue;
		for (int j = 2; i * j < 1000001; j++)
		{
			arr[i * j] = 1;
		}
	}

	int t;
	scanf("%d", &t);

	int num;
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &num);
		
		int count = 0;
		for (int j = 2; j < num; j++)
		{
			if (arr[num - j] != 1 && arr[j] != 1)
			{
				count++;
				if (num - j == j)
					count++;
			}
		}
		printf("%d\n", count / 2);
	}

	return 0;
}