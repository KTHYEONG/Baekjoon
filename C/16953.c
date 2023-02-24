#include <stdio.h>  // A --> B
#include <stdlib.h>

int ans = 1000000000;

typedef struct
{
	long long data;
	int cnt;
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
	q->front = q->rear = NULL;
	q->size = 0;
}

int is_empty(QUEUE* q)
{
	if (q->size <= 0)
		return 1;
	else
		return 0;
}

void push(QUEUE* q, int data, int cnt_num)
{
	node* newnode = malloc(sizeof(node));
	newnode->next = NULL;
	newnode->data = data;
	newnode->cnt = cnt_num;
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
		temp = q->front;
		node RETURN;
		RETURN.data = temp->data;
		RETURN.cnt = temp->cnt;
		q->front = temp->next;
		(q->size)--;
		free(temp);

		return RETURN;
	}
}

void bfs(QUEUE* q, long long a, long long b)
{
	push(q, a, 1);
	while (!is_empty(q))
	{
		node temp = pop(q);
		if (temp.data == b)
		{
			ans = temp.cnt;
			return;
		}
		
		if (temp.data * 2 <= b)
		{
			push(q, temp.data * 2, temp.cnt + 1);
		}
			
		
		if ((temp.data * 10) + 1 <= b)
		{
			push(q, (temp.data * 10) + 1, temp.cnt + 1);
		}
	}
}

/*void dfs(long long a, int cnt, long long b)
{
	if (b < a)
		return;

	if (a == b)
	{
		ans = min(ans, cnt);
		return;
	}

	dfs(a * 2, cnt + 1, b);
	dfs((a * 10) + 1, cnt + 1, b);
}*/


int main()
{
	long long a, b;
	scanf("%lld %lld", &a, &b);
	
	QUEUE q;
	init_QUEUE(&q);

	bfs(&q, a, b);
	if (ans == 1000000000)
		printf("%d", -1);
	else
		printf("%d", ans);

	return 0;
}