#include <stdio.h>  // 최댓값

int main()
{
	int arr[9], index, max = 0;

	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] > max)
		{
			max = arr[i];
			index = i;
		}
	}

	printf("%d\n%d", max, index);

	return 0;
}


/* for (int i = 0; i < 8; i++)             // 버블정렬 --> 시간초과
	{
		for (int j = 0; j < 9 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	printf("%d\n%d", arr[8], 8); */