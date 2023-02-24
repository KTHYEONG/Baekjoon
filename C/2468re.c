#include <stdio.h>  // 안전 영역
#include <stdlib.h>

int graph[101][101];
int copy[101][101];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void dfs(int x, int y, int num, int n)
{
	copy[x][y] = 0;

	for (int i = 0; i < 4; i++)
	{
		int move_x = x + dx[i];
		int move_y = y + dy[i];

		if (move_x < 0 || move_y < 0 || move_x >= n || move_y >= n)
			continue;

		if (copy[move_x][move_y] != 0)
		{
			dfs(move_x, move_y, num, n);
		}
	}
}

int solution(int n, int max)
{
	int ans = 0;
	for (int num = 0; num <= max; num++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				copy[i][j] = graph[i][j];
				if (copy[i][j] <= num)
					copy[i][j] = 0;
			}
		}

		int cnt = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (copy[i][j] != 0)
				{
					dfs(i, j, num, n);
					cnt++;
				}
			}
		}
		if (cnt > ans)
			ans = cnt;
	}

	return ans;
}


int main()
{
	int n;
	scanf("%d", &n);
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &graph[i][j]);
			if (graph[i][j] > max)
				max = graph[i][j];
		}
	}

	printf("%d", solution(n, max));


	return 0;
}