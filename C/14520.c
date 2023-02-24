#include <stdio.h>  // ¿¬±¸¼Ò
#include <stdlib.h>

#define max(a, b) a >= b ? a : b

int graph[8][8];
int graph_copy1[8][8];
int graph_copy2[8][8];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int ans = 0;

typedef struct
{
	struct node* next;
	int data_x;
	int data_y;
}node;

typedef struct
{
	node* front;
	node* rear;
	int count;
}queue;

void init_queue(queue* q)
{
	q->count = 0;
	q->front = q->rear = NULL;
}

int is_empty(queue* q)
{
	if (q->count <= 0)
		return 1;
	else
		return 0;
}

void push(queue* q, int x, int y)
{
	node* newnode = malloc(sizeof(node));
	newnode->data_x = x;
	newnode->data_y = y;
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
	q->count++;
}

node pop(queue* q)
{
	if (is_empty(q))
		return;
	else
	{
		node* temp;
		node RETURN;
		temp = q->front;
		RETURN.data_x = temp->data_x;
		RETURN.data_y = temp->data_y;
		q->front = temp->next;
		q->count--;
		free(temp);

		return RETURN;
	}
}

void bfs(queue *q, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			graph_copy2[i][j] = graph_copy1[i][j];
			if (graph_copy2[i][j] == 2)
			{
				push(q, i, j);
			}
		}
	}

	while (!is_empty(q))
	{
		node POP = pop(q);
		int x = POP.data_x;
		int y = POP.data_y;
		for (int i = 0; i < 4; i++)
		{
			int move_x = x + dx[i];
			int move_y = y + dy[i];
			if (move_x >= 0 && move_y >= 0 && move_x < n && move_y < m)
			{
				if (graph_copy2[move_x][move_y] == 0)
				{
					graph_copy2[move_x][move_y] = 2;
					push(q, move_x, move_y);
				}
			}
		}
	}

	int safe = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (graph_copy2[i][j] == 0)
			{
				safe++;
			}
		}
	}

	ans = max(ans, safe);
}

void wall(queue *q, int n, int m, int cnt)
{
	if (cnt == 3)
	{
		bfs(q, n, m);
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (graph_copy1[i][j] == 0)
				{
					graph_copy1[i][j] = 1;
					wall(q, n, m, cnt + 1);
					graph_copy1[i][j] = 0;
				}
			}
		}
	}
}

void solution(queue *q, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (graph[i][j] == 0)
			{
				for (int a = 0; a < n; a++)
				{
					for (int b = 0; b < m; b++)
					{
						graph_copy1[a][b] = graph[a][b];
					}
				}

				graph_copy1[i][j] = 1;
				wall(q, n, m, 1);
				graph_copy1[i][j] = 0;
			}
		}
	}
}


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	queue q;
	init_queue(&q);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &graph[i][j]);
		}
	}

	solution(&q, n, m);
	printf("%d", ans);

	return 0;
}