#include <stdio.h>  // DFS¿Í BFS
#include <stdlib.h>

int graph[1001][1001] = { 0, };
int visit_dfs[1001] = { 0, };
int visit_bfs[1001] = { 0, };

typedef struct
{
	struct node* next;
	int data;
}node;

typedef struct
{
	node* rear;
	node* front;
	int count;
}queue;

void init_queue(queue* q)
{
	q->front = q->rear = NULL;
	q->count = 0;
}

int is_empty(queue* q)
{
	return q->count == 0;
}

void push(queue* q, int data)
{
	node* newnode = malloc(sizeof(node));
	newnode->data = data;
	newnode->next = NULL;

	if (is_empty(q))
		q->front = newnode;
	else
		q->rear->next = newnode;
	q->rear = newnode;
	q->count++;
}

int pop(queue* q)
{
	int data;
	node* ptr;
	if (is_empty(q))
		return -1;
	ptr = q->front;
	data = ptr->data;
	q->front = ptr->next;
	free(ptr);
	q->count--;

	return data;
}

void dfs(int v, int n)
{
	visit_dfs[v] = 1;
	printf("%d ", v);

	for (int i = 1; i <= n; i++)
	{
		if (graph[v][i] == 1 && visit_dfs[i] == 0)
			dfs(i, n);
	}
}

void bfs(int v, int n)
{
	visit_bfs[v] = 1;
	printf("%d ", v);

	int temp;

	queue q;
	init_queue(&q);
	push(&q, v);

	while (!is_empty(&q))
	{
		temp = pop(&q);
		for (int i = 1; i <= n; i++)
		{
			if (graph[temp][i] == 1 && visit_bfs[i] == 0)
			{
				visit_bfs[i] = 1;
				printf("%d ", i);
				push(&q, i);
			}
		}
	}

}


int main()
{
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);

	int a, b;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	dfs(v, n);
	printf("\n");
	bfs(v, n);

	return 0;
}