#include <stdio.h>  // Ä«µå
#include <stdlib.h>

typedef struct
{
	struct node* next;
	struct node* prev;
	int data;
}node;

typedef struct
{
	node* rear;
	node* front;
}DEQUE;

void init_DEQUE(DEQUE* dq)
{
	dq->rear = dq->front = NULL;
}

int is_empty(DEQUE* dq)
{
	if (dq->front == NULL)
		return 1;
	else
		return 0;
}

void push_rear(DEQUE* dq, int data)
{
	node* newnode = malloc(sizeof(node));
	newnode->data = data;
	newnode->prev = dq->rear;

	if (is_empty(dq))
	{
		dq->front = newnode;
	}
	else
	{
		dq->rear->next = newnode;
	}
	newnode->next = NULL;
	dq->rear = newnode;
}

void push_front(DEQUE* dq, int data)
{
	node* newnode = malloc(sizeof(node));
	newnode->data = data;
	newnode->next = dq->front;

	if (is_empty(dq))
	{
		dq->rear = newnode;
	}
	else
	{
		dq->front->prev = newnode;
	}
	newnode->prev = NULL;
	dq->front = newnode;
}

int pop_rear(DEQUE* dq)
{
	if (is_empty(dq))
	{
		return;
	}
	else
	{
		node* temp;
		temp = dq->rear;
		int data = temp->data;
		dq->rear = temp->prev;
		free(temp);
		
		if (dq->rear == NULL)
		{
			dq->front = NULL;
		}
		else
		{
			dq->rear->next = NULL;
		}

		return data;
	}
}

int pop_front(DEQUE* dq)
{
	if (is_empty(dq))
	{
		return;
	}
	else
	{
		node* temp;
		temp = dq->front;
		int data = temp->data;
		dq->front = temp->next;
		free(temp);

		if (dq->front == NULL)
		{
			dq->rear = NULL;
		}
		else
		{
			dq->front->prev = NULL;
		}

		return data;
	}
}


int main()
{
	int n;
	scanf("%d", &n);

	DEQUE dq;
	init_DEQUE(&dq);
	push_rear(&dq, n);
	for (int i = n - 1; i > 0; i--)
	{
		push_front(&dq, i);
		for (int j = 0; j < i; j++)
		{
			int temp = pop_rear(&dq);
			push_front(&dq, temp);
		}
	}

	while (!is_empty(&dq))
	{
		printf("%d ", pop_front(&dq));
	}


	return 0;
}