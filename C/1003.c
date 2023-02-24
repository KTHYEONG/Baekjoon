#include <stdio.h>  // 피보나치 함수

int main()
{
	int t;
	scanf("%d", &t);

	// 0과 1의 개수를 저장
	int dp[41][2];
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;

	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);
		for (int j = 2; j <= n; j++)
		{
			dp[j][0] = dp[j - 1][0] + dp[j - 2][0];
			dp[j][1] = dp[j - 1][1] + dp[j - 2][1];
		}
		printf("%d %d\n", dp[n][0], dp[n][1]);
	}

	return 0;
}