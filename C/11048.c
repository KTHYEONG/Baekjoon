#include <stdio.h>  // �̵��ϱ�

#define max(a, b) a > b ? a : b

int arr[1001][1001] = { 0, };

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			arr[i][j] += max(max(arr[i - 1][j], arr[i][j - 1]), arr[i - 1][j - 1]);
		}
	}
	printf("%d", arr[n][m]);

	return 0;
}