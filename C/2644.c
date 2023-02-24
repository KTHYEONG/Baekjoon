#include <stdio.h>  // ÃÌ¼ö°è»ê
#include <stdlib.h>

int graph[101][101] = { 0, };
int visit[101] = { 0, };
int depth[101] = { 0, };

/*void dfs(int n, int now, int goal)
{
	visit[now] = 1;
	cnt++;

	if (now == goal)
	{
		ans = cnt;
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == 0 && graph[now][i] != 0)
		{
			dfs(n, i, goal);
		}
	}
	cnt--;
}*/

typedef struct
{
	int data;
	struct node* next;
}node;

typedef struct
{
	node* front;
	node* rear;
	int size;
}QUEUE;

void init_QUEUE(QUEUE* q)
{
	q->rear = q->front = NULL;
	q->size = 0;
}

int is_empty(QUEUE* q)
{
	if (q->size <= 0)
		return 1;
	else
		return 0;
}

void push(QUEUE* q, int data)
{
	node* newnode = malloc(sizeof(node));
	newnode->next = NULL;
	newnode->data = data;
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

int pop(QUEUE* q)
{
	if (is_empty(q))
	{
		return;
	}
	else
	{
		node* temp;
		temp = q->front;
		int data = temp->data;
		q->front = temp->next;
		(q->size)--;
		free(temp);

		return data;
	}
}

void bfs(QUEUE* q, int n, int now)
{
	visit[now] = 1;
	push(q, now);
	int POP;

	while (!is_empty(q))
	{
		POP = pop(q);
		for (int i = 1; i <= n; i++)
		{
			if (visit[i] == 0 && graph[POP][i] == 1)
			{
				visit[i] = 1;
				depth[i] = depth[POP] + 1;
				push(q, i);
			}
		}
	}
}


int main()
{
	int n;
	scanf("%d", &n);

	int goal1, goal2;
	scanf("%d %d", &goal1, &goal2);
	
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	QUEUE q;
	init_QUEUE(&q);

	bfs(&q, n, goal1);

	if (depth[goal2] != 0)
		printf("%d", depth[goal2]);
	else
		printf("%d", -1);

	return 0;
}