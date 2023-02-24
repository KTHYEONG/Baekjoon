#include <stdio.h>  // 나이트의 이동
#include <stdlib.h>

int graph[300][300];
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

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

int is_empty(queue *q)
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

void bfs(queue *q, int goal_x, int goal_y, int l)
{
	int flag = 0;
	while (!is_empty(q))
	{
		node POP = pop(q);
		int x = POP.data_x;
		int y = POP.data_y;
		for (int i = 0; i < 8; i++)
		{
			int move_x = x + dx[i];
			int move_y = y + dy[i];
			if (move_x >= 0 && move_y >= 0 && move_x < l && move_y < l)
			{
				if (graph[move_x][move_y] == 0)
				{
					graph[move_x][move_y] = graph[x][y] + 1;
					push(q, move_x, move_y);
				}
			}
		}
	}
}


int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int l;
		scanf("%d", &l);
		
		for (int j = 0; j < l; j++)
		{
			for (int k = 0; k < l; k++)
			{
				graph[j][k] = 0;
			}
		}

		int now_x, now_y;
		scanf("%d %d", &now_x, &now_y);
		graph[now_x][now_y] = 1;

		queue q;
		init_queue(&q);
		push(&q, now_x, now_y);

		int goal_x, goal_y;
		scanf("%d %d", &goal_x, &goal_y);

		bfs(&q, goal_x, goal_y, l);
		printf("%d\n", graph[goal_x][goal_y] - 1);
	}


	return 0;
}