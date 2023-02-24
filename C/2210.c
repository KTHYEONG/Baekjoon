#include <stdio.h>  // 숫자판 점프

int graph[5][5];
int visit[1000000] = { 0, };
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int ans = 0;

void dfs(int x, int y, int sum, int cnt)
{	
	if (cnt == 5)
	{
		// 값이 이전에 나오지 않은 조합인 경우
		// 값이 나왔음을 표시하고 카운트하기
		if (visit[sum] == 0)
		{
			visit[sum] = 1;
			ans++;
		}
		return;
	}

	// 위, 아래, 옆으로 확인
	for (int i = 0; i < 4; i++)
	{
		int move_x = dx[i] + x;
		int move_y = dy[i] + y;
		if (move_x >= 0 && move_y >= 0 && move_x < 5 && move_y < 5)
		{
			dfs(move_x, move_y, sum * 10 + graph[move_x][move_y], cnt + 1);
		}
	}
}

void solution()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			dfs(i, j, graph[i][j], 0);
		}
	}
}


int main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			scanf("%d", &graph[i][j]);
		}
	}
	
	solution();
	printf("%d", ans);

	return 0;
}