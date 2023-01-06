#include <stdio.h>  // 카드 구매하기 2

int dp[10001] = { 0, };

int MIN(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}


int main()
{
	int n;
	scanf("%d", &n);

	int arr[1001] = { 0, };
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	for (int i = 1; i <= n; i++)
	{
		dp[i] = 10001;
		for (int j = 1; j <= i; j++)
		{
			dp[i] = MIN(dp[i], dp[i - j] + arr[j]);
		}
	}

	printf("%d", dp[n]);

	return 0;
}