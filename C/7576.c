#include <stdio.h>  // ≈‰∏∂≈‰
#include <stdlib.h>

int graph[1000][1000];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int cnt = 0;

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

void push(queue *q, int x, int y)
{
	node* temp = malloc(sizeof(node));
	temp->data_x = x;
	temp->data_y = y;
	temp->next = NULL;
	if (is_empty(q))
	{
		q->front = temp;
	}
	else
	{
		q->rear->next = temp;
	}
	q->rear = temp;
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

void bfs(queue *q, int m, int n)
{
	int x, y;
	while (!is_empty(q))
	{
		node POP = pop(q);
		x = POP.data_x;
		y = POP.data_y;
		for (int i = 0; i < 4; i++)
		{
			int move_x = x + dx[i];
			int move_y = y + dy[i];
			if (move_x >= 0 && move_y >= 0 && move_x < n && move_y < m)
			{
				if (graph[move_x][move_y] == 0)
				{
					graph[move_x][move_y] = graph[x][y] + 1;
					push(q, move_x, move_y);
					cnt--;
				}
			}
		}
	}

	if (cnt == 0)
		printf("%d", graph[x][y] - 1);
	else
		printf("-1");
}


int main()
{
	int m, n;
	scanf("%d %d", &m, &n);

	queue q;
	init_queue(&q);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == 1)
				push(&q, i, j);
			else if (graph[i][j] == 0)
				cnt++;
		}
	}
	
	bfs(&q, m, n);

	return 0;
}