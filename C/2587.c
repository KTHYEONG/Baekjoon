#include <stdio.h>  // ´ëÇ¥°ª2

int main()
{
	int arr[5], sum = 0;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	int avg = sum / 5;

	int mid, key, j;
	for (int i = 1; i < 5; i++)
	{
		key = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > key; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}

	mid = arr[2];
	printf("%d\n%d", avg, mid);

	return 0;
}