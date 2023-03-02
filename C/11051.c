#include <stdio.h>  // 이항 계수 2

int dp[1001][1001];

void nCr(int n, int r)
{
	dp[1][1] = 1;
	dp[1][0] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = 1;
		for (int j = 1; j < i; j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
		}
		dp[i][i] = 1;
	}
}


int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	nCr(n, k);
	printf("%d", dp[n][k]);

	return 0;
}