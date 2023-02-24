#include <stdio.h>  // 요세푸스 문제 0
#include <stdlib.h>

typedef struct
{
	int data;
	struct node* next;
}node;

typedef struct
{
	node* front;
	node* rear;
	int cnt;
}queue;

void init_queue(queue* q)
{
	q->front = q->rear = NULL;
	q->cnt = 0;
}

int is_empty(queue* q)
{
	if (q->cnt <= 0)
		return 1;
	else
		return 0;
}

void push(queue* q, int data)
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
	q->cnt++;
}

int pop(queue* q)
{
	if (is_empty(q))
		return -1;
	else
	{
		node* temp;
		temp = q->front;
		int data = temp->data;
		q->front = temp->next;
		q->cnt--;
		free(temp);

		return data;
	}
}


int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	queue q;
	init_queue(&q);
	
	for (int i = 1; i <= n; i++)
	{
		push(&q, i);
	}

	printf("<");
	while (q.cnt != 1)
	{
		for (int i = 0; i < k - 1; i++)
		{
			// 뒤로 보내기
			int temp = pop(&q);
			push(&q, temp);
		}
		printf("%d, ", pop(&q));
	}
	printf("%d>", pop(&q));
	

	return 0;
}