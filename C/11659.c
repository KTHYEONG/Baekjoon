#include <stdio.h>  // 구간 합 구하기 4


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int arr[100001];
	int ans[100001] = { 0, };
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
		ans[i] = ans[i - 1] + arr[i];
	}

	for (int i = 0; i < m; i++)
	{
		int start, end;
		scanf("%d %d", &start, &end);
		printf("%d\n", ans[end] - ans[start - 1]);
	}

	return 0;
}