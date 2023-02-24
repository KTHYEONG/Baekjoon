#include <stdio.h> // 최소, 최대

int main()
{	
	int N, num;
	scanf("%d", &N);
	
	int max = -1000000, min = 1000000;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &num);
		if (num > max)
		{
			max = num;
		}

		if (num < min)
		{
			min = num;
		}
	}

	printf("%d %d", min, max);

	return 0;
}


/* for (int i = 0; i < N - 1; i++)           // 버블정렬 --> 시간초과
	{
		for (int j = 0; j < N - 1 - i; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	} */


	/* int j;
	for (int i = 1; i < N; i++)              // 삽입정렬 --> 시간초과
	{
		j = i - 1;
		temp = arr[i];
		while (j >= 0 && temp < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	} */