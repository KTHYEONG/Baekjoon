/*#include <stdio.h>  // 바이러스

int graph[101][101] = { 0, };
int visit[101] = { 0, };
int ans = 0;

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

void bfs(int num, int pc)
{
	queue q;
	init_queue(&q);

	visit[num] = 1;
	push(&q, num);

	while (!is_empty(&q))
	{
		int temp = pop(&q);
		for (int i = 1; i <= pc; i++)
		{
			if (visit[i] == 0 && graph[temp][i] == 1)
			{
				visit[i] = 1;
				push(&q, i);
				ans++;
			}
		}
	}

}


int main()
{
	int pc;
	scanf("%d", &pc);

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}

	bfs(1, pc);
	printf("%d", ans);

	return 0;
}*/

/* #include <stdio.h>

int graph[101][101];
int visit[101] = { 0, };
int ans = 0;

void dfs(int num, int pc)
{
	visit[num] = 1;

	for (int i = 1; i <= pc; i++)
	{
		if (visit[i] == 0 && graph[num][i] == 1)
		{
			dfs(i, pc);
			ans++;
		}
	}
}


int main()
{
	int pc;
	scanf("%d", &pc);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}

	dfs(1, pc);
	printf("%d", ans);

	return 0;
} */

#include <stdio.h>

#define INF 999999
#define min(a, b) a > b ? b : a

int graph[101][101];
int ans[101][101];
int cnt = 0;

void solution(int pc)
{
	for (int i = 1; i <= pc; i++)
	{
		for (int j = 1; j <= pc; j++)
		{
			ans[i][j] = graph[i][j];
		}
	}

	// 플로이드-워셜
	for (int k = 1; k <= pc; k++)
	{
		for (int i = 1; i <= pc; i++)
		{
			for (int j = 1; j <= pc; j++)
			{
				ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
			}
		}
	}

	// 1 과 연결되어 있는 노드 카운트
	for (int i = 2; i <= pc; i++)
	{
		if (ans[1][i] != INF)
			cnt++;
	}
}


int main()
{
	int pc;
	scanf("%d", &pc);

	for (int i = 1; i <= pc; i++)
	{
		for (int j = 1; j <= pc; j++)
		{
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = INF;
		}
	}

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
		
	solution(pc);
	printf("%d", cnt);

	return 0;
}