#include <stdio.h>  // 스타트링크
#include <stdlib.h>

int ans = -1;
int visit[1000001] = { 0, };

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

void bfs(QUEUE* q, int top, int start, int end, int up, int down)
{
	push(q, start, 0);
	visit[start] = 1;
	while (!is_empty(q))
	{
		node temp = pop(q);
		if (temp.data == end)
		{
			ans = temp.cnt;
			return;
		}

		if ((temp.data + up) <= top && visit[temp.data + up] == 0)
		{
			push(q, temp.data + up, temp.cnt + 1);
			visit[temp.data + up] = 1;
		}

		if ((temp.data - down) > 0 && visit[temp.data - down] == 0)
		{
			push(q, temp.data - down, temp.cnt + 1);
			visit[temp.data - down] = 1;
		}
	}
}


int main()
{
	int top, start, end, up, down;
	scanf("%d %d %d %d %d", &top, &start, &end, &up, &down);

	QUEUE q;
	init_QUEUE(&q);

	if (start == end)
		printf("%d", 0);
	else
	{
		bfs(&q, top, start, end, up, down);
		if (ans != -1)
		{
			printf("%d", ans);
		}
		else
		{
			printf("use the stairs");
		}
	}

	return 0;
}