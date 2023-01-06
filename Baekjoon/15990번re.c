#include <stdio.h>  // 1, 2, 3 더하기 5  // 문제 이론만 다시 이해하기

#define	MOD 1000000009

long long int dp[100001][4];

int main()
{
	dp[1][1] = 1;
	dp[1][2] = 0;
	dp[1][3] = 0;

	dp[2][1] = 0;
	dp[2][2] = 1;
	dp[2][3] = 0;

	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;

	int t;
	scanf("%d", &t);

	long long int n;
	for (int i = 1; i <= t; i++)
	{
		scanf("%lld", &n);
		for (int j = 4; j <= n; j++)
		{
			dp[j][1] = (dp[j - 1][2] + dp[j - 1][3]) % MOD;
			dp[j][2] = (dp[j - 2][1] + dp[j - 2][3]) % MOD;
			dp[j][3] = (dp[j - 3][1] + dp[j - 3][2]) % MOD;
		}
		printf("%lld\n", (dp[n][1] + dp[n][2] + dp[n][3]) % MOD);
	}

	return 0;
}