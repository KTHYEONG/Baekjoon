#include <stdio.h>  // »öÁ¾ÀÌ

int main()
{
	int n;
	scanf("%d", &n);

	int arr[100][100] = { 0, };
	int x, y;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		for (int j = x; j < x + 10; j++)
		{
			for (int k = y; k < y + 10; k++)
			{
				arr[j][k] = 1;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (arr[i][j] == 1)
				result++;
		}
	}
	
	printf("%d", result);

	return 0;
}