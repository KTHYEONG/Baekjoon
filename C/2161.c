#include <stdio.h>  // Ä«µå1
#include <stdlib.h>

typedef struct
{
	struct node* next;
	int data;
}node;

typedef struct
{
	node* rear;
	node* front;
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

void push(QUEUE* q, int data)
{
	node* newnode = malloc(sizeof(node));
	newnode->data = data;
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
	(q->size)++;
}

int pop(QUEUE* q)
{
	if (!is_empty(q))
	{
		node* temp;
		temp = q->front;
		int data = temp->data;
		q->front = temp->next;
		(q->size)--;

		free(temp);

		return data;
	}
	else
		return 1;
}


int main()
{
	int n;
	scanf("%d", &n);

	QUEUE q;
	init_QUEUE(&q);

	for (int i = 1; i <= n; i++)
	{
		push(&q, i);
	}

	while (1)
	{
		printf("%d ", pop(&q));

		if (is_empty(&q))
			break;

		int temp = pop(&q);
		push(&q, temp);
	}
	

	return 0;
}