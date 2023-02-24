#include <stdio.h>  // 단지번호붙이기
#include <stdlib.h>

int graph[26][26] = { 0, };
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int ans = 0;
int house[350];

void dfs(int x, int y, int n, int key)
{
	graph[x][y] = key;

	for (int i = 0; i < 4; i++)
	{
		int XX = x + dx[i];
		int YY = y + dy[i];

		if (XX >= 0 && YY >= 0 && XX < n && YY < n)
		{
			if (graph[XX][YY] == 1)
			{
				dfs(XX, YY, n, key);
			}
		}
	}		
}

void solution(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == 1)
			{
				ans++;
				dfs(i, j, n, ans + 1);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] > 1)
			{
				house[graph[i][j] - 2]++;
			}
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &graph[i][j]);
		
	solution(n);
	for (int i = 0; i < ans - 1; i++)
	{
		for (int j = 0; j < ans - 1 - i; j++)
		{
			if (house[j] > house[j + 1])
			{
				int temp = house[j];
				house[j] = house[j + 1];
				house[j + 1] = temp;
			}
		}
	}
	
	printf("%d\n", ans);
	for (int i = 0; i < ans; i++)
		printf("%d\n", house[i]);

	return 0;
}