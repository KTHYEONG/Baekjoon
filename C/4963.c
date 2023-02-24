#include <stdio.h>  // ¼¶ÀÇ °³¼ö  // ÁÂÇ¥ ¾²´Â °³³ä

int graph[51][51];
int visit[51][51];
int xx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int yy[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int cnt = 0;

void dfs(int x, int y, int w, int h)
{
	visit[x][y] = 1;

	for (int i = 0; i < 8; i++)
	{
		int check_x = x + xx[i];
		int check_y = y + yy[i];
		if (check_x >= 0 && check_x < h && check_y >= 0 && check_y < w)			// ÀÎµ¦½º ÃÊ°ú ¹üÀ§ Á¦¿Ü
		{
			if (visit[check_x][check_y] == 0 && graph[check_x][check_y] == 1)
				dfs(check_x, check_y, w, h);
		}
	}
}

void check(int w, int h)
{
	cnt = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (visit[i][j] == 0 && graph[i][j] == 1)
			{
				dfs(i, j, w, h);
				cnt++;
			}
		}
	}
}


int main()
{
	int w, h;
	while (1)
	{
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
				scanf("%d", &graph[i][j]);
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
				visit[i][j] = 0;
		}

		check(w, h);
		printf("%d\n", cnt);
	}

	
	return 0;
}