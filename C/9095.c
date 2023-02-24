/*#include <stdio.h>  // 1, 2, 3 더하기  // dp == 규칙 찾고 점화식 만들기

int dp[10000] = { 0, };

int main()
{

	dp[1] = 1; dp[2] = 2; dp[3] = 4;

	int t;
	scanf("%d", &t);

	int n;
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		
		for (int j = 4; j <= n; j++)
		{
			dp[j] = dp[j - 3] + dp[j - 2] + dp[j - 1];
		}

		printf("%d\n", dp[n]);
	}

	return 0;
}*/

/* #include <stdio.h>

int result = 0;

void dfs(int n)
{
	if (n == 0)
		result++;
	else
	{
		if (n > 0)
		{
			for (int i = 1; i <= 3; i++)
				dfs(n - i);
		}
	}
}


int main()
{
	int t;
	scanf("%d", &t);

	int n;
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		dfs(n);
		printf("%d\n", result);
		result = 0;
	}

	return 0;
}*/

#include <stdio.h>
#include <stdlib.h>

int result = 0;

typedef struct
{
	int data;
	struct node* next;
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
	if (q->count <= 0)
		return 1;
	else
		return 0;
}

void push(queue* q, int data)
{
	node* temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;

	if (is_empty(q))
	{
		q->front = temp;
	}
	else
	{
		q->rear->next = temp;
	}
	q->rear= temp;
	q->count++;
}

int pop(queue* q)
{
	if (is_empty(q))
		return 0;
	else
	{
		int data;
		node* temp = (node*)malloc(sizeof(node));
		temp = q->front;
		data = temp->data;
		q->front = temp->next;
		q->count--;
		free(temp);

		return data;
	}
}

void bfs(int n)
{
	queue q;
	init_queue(&q);
	push(&q, 0);
	int temp = 0;
	
	while (1)
	{
		if (is_empty(&q))
			break;
		
		temp = pop(&q);
		if (n == temp)
			result++;
			
		if (temp + 1 <= n)
			push(&q, temp + 1);

		if (temp + 2 <= n)
			push(&q, temp + 2);

		if (temp + 3 <= n)
			push(&q, temp + 3);
	}
}


int main()
{
	int t;
	scanf("%d", &t);

	int n;
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		bfs(n);
		printf("%d\n", result);
		result = 0;
	}

	return 0;
}