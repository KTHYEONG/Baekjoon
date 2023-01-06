/*#include <stdio.h>  // 1, 2, 3 더하기  // dp == 규칙 찾고 점화식 만들기

int dp[10000] = { 0, };

int main()
{

	dp[1] = 1; dp[2] = 2; dp[3] = 4;

	int t;
	scanf("%d", &t);

	int n;
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		
		for (int j = 4; j <= n; j++)
		{
			dp[j] = dp[j - 3] + dp[j - 2] + dp[j - 1];
		}

		printf("%d\n", dp[n]);
	}

	return 0;
}*/

#include <stdio.h>

int result = 0;

void dfs(int n)
{
	if (n == 0)
		result++;
	else
	{
		if (n > 0)
		{
			for (int i = 1; i <= 3; i++)
				dfs(n - i);
		}
	}
}


int main()
{
	int t;
	scanf("%d", &t);

	int n;
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		dfs(n);
		printf("%d\n", result);
		result = 0;
	}

	return 0;
}