#include <stdio.h>  // 미로 탐색
#include <stdlib.h>

int graph[101][101] = { 0, };
int visit[10001][2] = { 0, };
int xx[4] = { 1, -1, 0, 0 };
int yy[4] = { 0, 0, -1, 1 };

int bfs(int n, int m)
{
	int front = 0, rear = 0;
	visit[front][0] = 1;			// 처음 시작 좌표
	visit[front][1] = 1;
	rear++;

	while (front < rear)
	{
		int x = visit[front][0];
		int y = visit[front][1];
		front++;
		
		// 상하좌우 체크
		for (int i = 0; i < 4; i++)			
		{
			int move_x = x + xx[i];
			int move_y = y + yy[i];

			// 인덱스 범위 벗어나는 경우 제외
			if (move_x > n || move_x < 1 || move_y > m || move_y < 1)			
				continue;

			// 길이 아닌 경우
			if (graph[move_x][move_y] != 1)
				continue;

			graph[move_x][move_y] = graph[x][y] + 1;

			visit[rear][0] = move_x;
			visit[rear][1] = move_y;
			rear++;
		}
	}

	return graph[n][m];
}


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%1d", &graph[i][j]);
		}	
	}

	printf("%d", bfs(n, m));

	return 0;
}