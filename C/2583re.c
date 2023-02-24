#include <stdio.h>  // 영역 구하기

int graph[101][101];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int cnt = 0;
int area[101] = { 0, };

void dfs(int x, int y, int key, int m, int n)
{
	graph[x][y] = key;
	area[key - 2]++;
	for (int i = 0; i < 4; i++)
	{
		int move_x = x + dx[i];
		int move_y = y + dy[i];

		if (move_x >= 0 && move_y >= 0 && move_x < n && move_y < m)
		{
			if (graph[move_x][move_y] == 0)
			{
				dfs(move_x, move_y, key, m, n);
			}
		}
	}
}

void solution(int m, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (graph[i][j] == 0)
			{
				cnt++;
				dfs(i, j, cnt + 1, m, n);
			}
		}
	}
}


int main()
{
	int m, n, k;
	scanf("%d %d %d", &m, &n, &k);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			graph[i][j] = 0;
		}
	}

	for (int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int j = y1; j < y2; j++)
		{
			for (int k = x1; k < x2; k++)
			{
				graph[k][j] = 1;
			}
		}
	}

	solution(m, n);
	printf("%d\n", cnt);

	for (int i = 0; i < cnt - 1; i++)
	{
		for (int j = 0; j < cnt - 1 - i; j++)
		{
			if (area[j] > area[j + 1])
			{
				int temp = area[j];
				area[j] = area[j + 1];
				area[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < cnt; i++)
		printf("%d ", area[i]);

	return 0;
}