#include <stdio.h>  // 골드바흐의 추측

int main()
{
	int arr[10001] = { 0, };
	arr[1] = 1;
	for (int i = 2; i < 10001; i++)			// 소수 x -> 1로 구분하는 배열 
	{
		for (int j = 2; i * j < 10001; j++)
		{
			arr[i * j] = 1;
		}
	}

	int T, n;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &n);
		for (int j = n / 2; j > 0; j--)			// n의 절반 값 --> 합을 하게 될 두 개의 수의 차이가 제일 적어짐
		{
			if (arr[j] != 1 && arr[n - j] != 1)
			{
				printf("%d %d\n", j, n - j);
				break;
			}
		}

	}

	return 0;
}