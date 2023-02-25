#include <stdio.h>  // º¸¹°¼¶
#include <stdlib.h>
#include <string.h>

#define max(a, b) a > b ? a : b

char graph[51][51];
int visit[51][51];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int ans = -1;

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

void push(QUEUE* q, int x, int y)
{
	node* newnode = malloc(sizeof(node));
	newnode->x = x;
	newnode->y = y;
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
		node* temp;
		node RETURN;
		temp = q->front;
		RETURN.x = temp->x;
		RETURN.y = temp->y;
		q->front = temp->next;
		(q->size)--;
		free(temp);

		return RETURN;
	}
}

int bfs(int x, int y, int n, int m)
{
	QUEUE q;
	init_QUEUE(&q);
	push(&q, x, y);
	visit[x][y] = 1;

	int result = 0;
	while (!is_empty(&q))
	{
		node temp = pop(&q);
		if (result < visit[temp.x][temp.y])
		{
			result = visit[temp.x][temp.y];
		}
		for (int i = 0; i < 4; i++)
		{
			int move_x = temp.x + dx[i];
			int move_y = temp.y + dy[i];
			if (move_x >= 0 && move_y >= 0 && move_x < n && move_y < m)
			{
				if (graph[move_x][move_y] == 'L' && visit[move_x][move_y] == 0)
				{
					visit[move_x][move_y] = visit[temp.x][temp.y] + 1;
					push(&q, move_x, move_y);
				}
			}
		}
	}
	return result;
}

void solution(int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (graph[i][j] == 'L')
			{
				memset(visit, 0, sizeof(visit));
				int temp = bfs(i, j, n, m);
				ans = max(ans, temp);
			}
		}
	}
}


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf(" %c", &graph[i][j]);
		}
	}
	solution(n, m);
	printf("%d", ans - 1);

	return 0;
}