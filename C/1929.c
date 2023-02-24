/*#include <stdio.h>  // 소수 구하기

int arr[1000001] = { 0, };

int main(void)
{
	int M, N;
	scanf("%d %d", &M, &N);
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
}*/

#include <stdio.h>			// 에라토스테네스의 체(복습)

int arr[1000001];

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);

	for (int i = 0; i < 1000001; i++)
		arr[i] = 0;

	arr[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (arr[i] == 1)
			continue;
		for (int j = 2; i * j <= n; j++)
		{
			arr[i * j] = 1;
		}
	}

	for (int i = m; i <= n; i++)
	{
		if (arr[i] != 1)
			printf("%d\n", i);
	}

	return 0;
}