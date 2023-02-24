#include <stdio.h>  // 1, 2, 3 ¥ı«œ±‚ 3

long long int dp[1000001];

int main()
{
	dp[1] = 1; dp[2] = 2; dp[3] = 4;

	int t;
	scanf("%d", &t);

	int n;
	for (int i = 0; i <t; i++)
	{
		scanf("%d", &n);
		for (int j = 4; j <= n; j++)
		{
			dp[j] = (dp[j - 1] + dp[j - 2] + dp[j - 3]) % 1000000009;
		}
		printf("%lld\n", dp[n]);
	}

	return 0;
}