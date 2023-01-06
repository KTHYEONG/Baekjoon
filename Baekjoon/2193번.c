#include <stdio.h>  // 이친수  // dp --> 직접 경우의 수 구해보고 패턴 찾아보기

long long int dp[91];

int main()
{
	int n;
	scanf("%d", &n);
	
	dp[1] = 1; dp[2] = 1; dp[3] = 2;
	for (int i = 4; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	printf("%lld", dp[n]);

	return 0;
}