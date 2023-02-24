/* #include <stdio.h>  // 연결 요소의 개수

int graph[1001][1001] = { 0, };
int visit[1001] = { 0, };
int cnt = 0;

void dfs(int num, int n)
{
	visit[num] = 1;

	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == 0 && graph[num][i] == 1)
		{
			dfs(i, n);
		}
	}
}

void check(int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == 0)
		{
			cnt++;
			dfs(i, n);
		}
	}
}


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int u, v;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &u, &v);
		graph[u][v] = 1;
		graph[v][u] = 1;
	}

	check(n);
	printf("%d", cnt);
	

	return 0;
}*/

#include <stdio.h>  // 연결 요소의 개수
#include <stdlib.h>

int graph[1001][1001] = { 0, };
int visit[1001] = { 0, };
int cnt = 0;

typedef struct
{
	int data;
	struct node* next;
}node;

typedef struct
{
	int count;
	node* front;
	node* rear;
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

void push(queue* q, int data)
{
	node* temp = malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;

	if (is_empty(q))
		q->front = temp;
	else
		q->rear->next = temp;

	q->rear = temp;
	q->count++;
}

int pop(queue* q)
{
	node* temp = malloc(sizeof(node));
	if (is_empty(q))
		return -1;
	else
	{
		temp = q->front;
		int data = temp->data;
		q->front = temp->next;
		free(temp);
		q->count--;

		return data;
	}
}

void bfs(int num, int n)
{
	visit[num] = 1;
	
	queue q;
	init_queue(&q);
	push(&q, num);

	while (!is_empty(&q))
	{
		int temp = pop(&q);
		for (int i = 1; i <= n; i++)
		{
			if (graph[temp][i] == 1 && visit[i] == 0)
			{
				visit[i] = 1;
				push(&q, i);
			}
		}
	}
}

void check(int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == 0)
		{
			cnt++;
			bfs(i, n);
		}
	}
}


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int u, v;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &u, &v);
		graph[u][v] = 1;
		graph[v][u] = 1;
	}

	check(n);
	printf("%d", cnt);


	return 0;
}