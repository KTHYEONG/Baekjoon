#include <stdio.h>  // ÀÏ°ö ³­ÀïÀÌ

int main()
{
	int sum = 0, arr[9];
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	int temp;
	for (int i = 0; i < 8; i++)			// ¹öºíÁ¤·Ä
	{
		for (int j = 0; j < 8 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - (arr[i] + arr[j]) == 100)
			{
				for (int k = 0; k < 9; k++)
				{
					if (k != i && k != j)
						printf("%d\n", arr[k]);
				}

				return 0;
			}
		}
	}

	return 0;
}