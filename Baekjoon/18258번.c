#include <stdio.h>  // 큐 2
#include <stdlib.h>
#include <string.h>

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

void init_queue(queue *q)
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

void front(queue* q)
{
	if (is_empty(q))
		printf("%d\n", -1);
	else
		printf("%d\n", q->front->data);
}

void back(queue* q)
{
	if (is_empty(q))
		printf("%d\n", -1);
	else
		printf("%d\n", q->rear->data);
}


int main()
{
	int n;
	scanf("%d", &n);

	queue q;
	init_queue(&q);

	char str[6];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		if (!strcmp(str, "push"))
		{
			int data;
			scanf("%d", &data);
			push(&q, data);
		}
		else if (!strcmp(str, "pop"))
		{
			printf("%d\n", pop(&q));
		}
		else if (!strcmp(str, "size"))
		{
			printf("%d\n", q.count);
		}
		else if (!strcmp(str, "empty"))
		{
			if (is_empty(&q))
				printf("%d\n", 1);
			else
				printf("%d\n", 0);
		}
		else if (!strcmp(str, "front"))
		{
			front(&q);
		}
		else if (!strcmp(str, "back"))
		{
			back(&q);
		}
	}

	return 0;
}