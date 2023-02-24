#include <stdio.h>  // 카드 구매하기

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int dp[10000] = { 0, };

int main()
{
	int n;
	scanf("%d", &n);

	int arr[10000] = { 0, };
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + arr[j]);
		}
	}
	printf("%d", dp[n]);

	return 0;
}