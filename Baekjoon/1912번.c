#include <stdio.h>  // 연속합  // 코드 이해 다시

#define max(a, b) a > b ? a : b 

int arr[100000];
int dp[100000];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	int result = arr[0];
	dp[0] = arr[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		result = max(dp[i], result);
	}

	printf("%d", result);

	return 0;
}