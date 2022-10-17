#include <stdio.h>  // 소수 구하기

int main(void)
{
	int M, N;
	scanf("%d %d", &M, &N);

	int arr[100001] = { 0, };
	arr[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; i * j <= N; j++)
		{
			arr[i * j] = 1;
		}
	}

	for (int i = M; i <= N; i++)
	{
		if (arr[i] == 0)
			printf("%d\n", i);
	}

	return 0;
}