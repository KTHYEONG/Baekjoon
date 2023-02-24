/* #include <stdio.h>  // 경로 찾기

int graph[101][101];
int visit[101] = { 0, };

void dfs(int k, int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == 0 && graph[k][i] == 1)
		{
			visit[i] = 1;
			dfs(i, n);
		}
	}
}

void solution(int n)
{
	for (int i = 1; i <= n; i++)
	{
		dfs(i, n);
		for (int i = 1; i <= n; i++)
		{
			if (visit[i] == 1)
			{
				printf("1 ");
			}
			else
			{
				printf("0 ");
			}
		}
		printf("\n");

		for (int i = 1; i <= n; i++)
		{
			visit[i] = 0;
		}
	}
}


int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &graph[i][j]);
		}
	}

	solution(n);

	return 0;
} */

#include <stdio.h>  // 경로 찾기			// 플로이드-워셜

#define INF 9999999
#define min(a, b) a > b ? b : a

int graph[101][101];

void solution(int n)
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] == INF)
			{
				printf("0 ");
			}
			else
			{
				printf("1 ");
			}
		}
		printf("\n");
	}
}


int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == 0)
				graph[i][j] = INF;
		}
	}

	solution(n);

	return 0;
}