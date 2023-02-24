#include <stdio.h>  // 골드바흐의 추측

int arr[1000001] = { 0, };

int main()
{
	// 에라토스테네스의 체
	for (int i = 2; i < 1000001; i++)
	{
		if (arr[i] == 1)
			continue;
		for (int j = 2; i * j < 1000001; j++)
		{
			arr[i * j] = 1;
		}
	}

	return 0;
}
/*
#include <stdio.h>  // 골드바흐의 추측

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

	int num;
	while (1)
	{
		scanf("%d", &num);
		if (num == 0)
			break;
		for (int i = 3; i < 1000001; i++)
		{
			if (num - i <= 0)
			{
				printf("Goldbach's conjecture is wrong.\n");
				break;
			}
			else if (arr[num - i] != 1 && arr[i] != 1)
			{
				printf("%d = %d + %d\n", num, i, num - i);
				break;
			}
		}
	}


	return 0;
}
*/