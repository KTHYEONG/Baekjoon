#include <stdio.h>  // 2 x n 타일링 2  // 이러한 방식(점화식)으로 dp를 해결한다는 점 복습

int dp[10008] = { 0, };

int main()
{
	int n;
	scanf("%d", &n);

	dp[1] = 1; dp[2] = 3;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
	}

	printf("%d", dp[n]);

	return 0;
}