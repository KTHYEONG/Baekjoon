#include <stdio.h>  // 2 x n ≈∏¿œ∏µ

dp[10008] = { 0, };

int main()
{
	int n;
	scanf("%d", &n);

	dp[1] = 1; dp[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
	}

	printf("%d", dp[n]);

	return 0;
}