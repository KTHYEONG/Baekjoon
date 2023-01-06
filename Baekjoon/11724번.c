#include <stdio.h>  // 연결 요소의 개수

int graph[1001][1001] = { 0, };


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int u, v;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &u, &v);
		graph[u][v] = 1;

	}

	return 0;
}