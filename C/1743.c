#include <stdio.h>  // 음식물 피하기
#include <stdlib.h>

#define max(a, b) a > b ? a : b

int graph[101][101] = { 0, };
int visit[101][101] = { 0, };
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int ans = 0;
int cnt = 1;

typedef struct
{
	int x;
	int y;
	struct node* next;
}node;

typedef struct
{
	node* rear;
	node* front;
	int size;
}QUEUE;

void init_QUEUE(QUEUE* q)
{
	q->size = 0;
	q->rear = q->front = NULL;
}

int is_empty(QUEUE* q)
{
	if (q->size <= 0)
		return 1;
	else
		return 0;
}

void push(QUEUE* q, int data_x, int data_y)
{
	node* newnode = malloc(sizeof(node));
	newnode->x = data_x;
	newnode->y = data_y;
	newnode->next = NULL;
	if (is_empty(q))
	{
		q->front = newnode;
	}
	else
	{
		q->rear->next = newnode;
	}
	q->rear = newnode;
	(q->size)++;
}

node pop(QUEUE* q)
{
	if (is_empty(q))
	{
		return;
	}
	else
	{
		node* temp = q->front;
		node RETURN;
		RETURN.x = temp->x;
		RETURN.y = temp->y;
		q->front = temp->next;
		(q->size)--;
		free(temp);

		return RETURN;
	}
}

void bfs(QUEUE* q, int x, int y, int n, int m)
{
	push(q, x, y);
	visit[x][y] = 1;

	while (!is_empty(q))
	{
		node temp = pop(q);
		for (int i = 0; i < 4; i++)
		{
			int move_x = temp.x + dx[i];
			int move_y = temp.y + dy[i];
			if (move_x >= 1 && move_y >= 1 && move_x <= n && move_y <= m)
			{
				if (visit[move_x][move_y] == 0 && graph[move_x][move_y] == 1)
				{
					visit[move_x][move_y] = 1;
					push(q, move_x, move_y);
					cnt++;
				}
			}
		}
	}
}

void solution(QUEUE* q, int n, int m)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (visit[i][j] == 0 && graph[i][j] == 1)
			{
				bfs(q, i, j, n, m);
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
	}
}


int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < k; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
	}

	QUEUE q;
	init_QUEUE(&q);

	solution(&q, n, m);
	printf("%d", ans);

	return 0;
}

/*void dfs(int x, int y, int n, int m)
{
	visit[x][y] = 1;
	cnt++;

	for (int i = 0; i < 4; i++)
	{
		int move_x = x + dx[i];
		int move_y = y + dy[i];
		if (move_x >= 1 && move_y >= 1 && move_x <= n && move_y <= m)
		{
			if ((visit[move_x][move_y] == 0) && (graph[move_x][move_y] == 1))
			{
				dfs(move_x, move_y, n, m);
			}
		}
	}
}*/