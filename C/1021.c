#include <stdio.h>  // 회전하는 큐
#include <stdlib.h>

typedef struct
{
	int data;
	struct node* prev;
	struct node* next;
}node;

typedef struct
{
	node* rear;
	node* front;
	int cnt;
}queue;

void init_queue(queue* q)
{
	q->cnt = 0;
	q->rear = q->front = NULL;
}

int is_empty(queue* q)
{
	if (q->cnt <= 0)
		return 1;
	else
		return 0;
}

int search(queue* q, int goal)
{
	int idx = (q->cnt + 1) / 2;
	node* temp = q->front;
	while (idx)
	{
		if (temp->data == goal)
		{
			// 앞쪽과 가까움, pop_front && push_rear 
			return 1;
		}
		temp = temp->next;
		idx--;
	}
	// 뒤쪽과 가까움, pop_rear && push_front
	return -1;
}

int front(queue* q)
{
	return q->front->data;
}

void push_rear(queue* q, int data)
{
	node* newnode = malloc(sizeof(node));
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = q->rear;
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

void push_front(queue* q, int data)
{
	node* newnode = malloc(sizeof(node));
	newnode->data = data;
	newnode->next = q->front;
	newnode->prev = NULL;
	if (is_empty(q))
	{
		q->rear = newnode;
	}
	else
	{
		q->front->prev = newnode;
	}
	q->front = newnode;
	q->cnt++;
}

int pop_front(queue* q)
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

int pop_rear(queue* q)
{
	if (is_empty(q))
		return -1;
	else
	{
		node* temp;
		temp = q->rear;
		int data = temp->data;
		q->rear = temp->prev;
		q->cnt--;
		free(temp);

		return data;
	}
}


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	queue q;
	init_queue(&q);

	// 1 ~ n 까지 push
	for (int i = 1; i <= n; i++)
	{
		push_rear(&q, i);
	}

	int num, cnt = 0;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &num);

		int temp;
		while (front(&q) != num)
		{
			if (search(&q, num) == 1)
			{
				temp = pop_front(&q);
				push_rear(&q, temp);
			}
			else
			{
				temp = pop_rear(&q);
				push_front(&q, temp);
			}
			cnt++;
		}
		pop_front(&q);
	}

	printf("%d", cnt);


	return 0;
}