#include <stdio.h>  // 유기농 배추
#include <stdlib.h>

int graph[51][51];
int visit[51][51];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int ans = 0;

typedef struct
{
	int data_x;
	int data_y;
	struct node* next;
}node;

typedef struct
{
	int size;
	node* front;
	node* rear;
}QUEUE;

void init_QUEUE(QUEUE* q)
{
	q->size = 0;
	q->front = q->rear = NULL;
}

int is_empty(QUEUE* q)
{
	if (q->size <= 0)
		return 1;
	else
		return 0;
}

void push(QUEUE* q, int data_y, int data_x)
{
	node* newnode = malloc(sizeof(node));
	newnode->data_x = data_x;
	newnode->data_y = data_y;
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
	q->size++;
}

node pop(QUEUE* q)
{
	if (is_empty(q))
		return;
	else
	{
		node pop_data;
		node* temp;
		temp = q->front;
		pop_data.data_x = temp->data_x;
		pop_data.data_y = temp->data_y;
		q->front = temp->next;
		q->size--;
		free(temp);

		return pop_data;
	}
}

void bfs(QUEUE* q, int y, int x, int m, int n)
{
	visit[y][x] = 1;
	push(q, y, x);

	while (!is_empty(q))
	{
		node POP = pop(q);
		int xx = POP.data_x;
		int yy = POP.data_y;
		for (int i = 0; i < 4; i++)
		{
			int move_x = xx + dx[i];
			int move_y = yy + dy[i];
			if (move_x >= 0 && move_y >= 0 && move_x < m && move_y < n)
			{
				if (visit[move_y][move_x] == 0 && graph[move_y][move_x] == 1)
				{
					visit[move_y][move_x] = 1;
					push(q, move_y, move_x);
				}
			}
		}
	}
}

void solution(QUEUE *q, int m, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visit[i][j] == 0 && graph[i][j] == 1)
			{
				bfs(q, i, j, m, n);
				ans++;
			}
		}
	}
}


int main()
{
	QUEUE q;
	init_QUEUE(&q);

	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int m, n, k;
		scanf("%d %d %d", &m, &n, &k);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				graph[i][j] = 0;

		for (int j = 0; j < k; j++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			graph[y][x] = 1;
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				visit[i][j] = 0;

		solution(&q, m, n);
		printf("%d\n", ans);
		ans = 0;
	}

	return 0;
}

/*void dfs(int y, int x, int m, int n)
{
	visit[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int XX = x + dx[i];
		int YY = y + dy[i];

		// 범위 벗어나는 경우
		if (XX < 0 || YY < 0 || XX >= m || YY >= n)
			continue;

		if (graph[YY][XX] == 1 && visit[YY][XX] == 0)
		{
			dfs(YY, XX, m, n);
		}
	}
}*/