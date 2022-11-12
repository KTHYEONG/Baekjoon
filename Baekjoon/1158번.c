#include <stdio.h>  // 요세푸스 문제
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
	int count;
}queue;

void init_queue(queue* q)
{
	q->front = q->rear = NULL;
	q->count = 0;
}

int is_empty(queue* q)
{
	if (q->count == 0)
		return 1;
	else
		return 0;
}

int front(queue* q)
{
	return q->front->data;
}

int size(queue* q)
{
	return q->count;
}

void push(queue* q, int data)
{
	node* newnode = malloc(sizeof(node));
	newnode->next = NULL;
	newnode->data = data;

	if (is_empty(q))
		q->front = newnode;
	else
		q->rear->next = newnode;
	q->rear = newnode;
	q->count++;
}

void pop(queue* q)
{
	int data;
	node* ptr;
	if (is_empty(q))
	{
		return -1;
	}
	else
	{
		ptr = q->front;
		data = ptr->data;
		q->front = ptr->next;
		free(ptr);
		q->count--;
	}
}

int main()
{
	queue q;
	init_queue(&q);

	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++)
		push(&q, i);

	printf("<");
	while (size(&q) - 1)
	{
		for (int i = 0; i < k - 1; i++)
		{
			push(&q, front(&q));
			pop(&q);
		}
		printf("%d, ", front(&q));
		pop(&q);
	}
	printf("%d", front(&q));
	printf(">");

	return 0;
}