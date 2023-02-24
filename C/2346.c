#include <stdio.h>  // 풍선 터뜨리기
#include <stdlib.h>

typedef struct
{
	int data;
	int idx;
	struct node* next;
	struct node* prev;
}node;

typedef struct
{
	node* front;
	node* rear;
}DEQUE;

void init_DEQUE(DEQUE* d)
{
	d->front = d->rear = NULL;
}

int is_empty(DEQUE* d)
{
	if (d->front == NULL)
		return 1;
	else
		return 0;
}

void push_rear(DEQUE* d, int data, int idx)
{
	node* newnode = malloc(sizeof(node));
	newnode->data = data;
	newnode->idx = idx;
	newnode->next = NULL;
	if (is_empty(d))
	{
		d->front = newnode;
	}
	else
	{
		d->rear->next = newnode;
	}
	newnode->prev = d->rear;
	d->rear = newnode;
}

void push_front(DEQUE* d, int data, int idx)
{
	node* newnode = malloc(sizeof(node));
	newnode->data = data;
	newnode->idx = idx;
	newnode->prev = NULL;
	if (is_empty(d))
	{
		d->rear = newnode;
	}
	else
	{
		d->front->prev = newnode;
	}
	newnode->next = d->front;
	d->front = newnode;
}

node pop_front(DEQUE* d)
{
	if (is_empty(d))
	{
		return;
	}
	else
	{
		node* temp = d->front;
		node return_data;
		return_data.data = temp->data;
		return_data.idx = temp->idx;
		d->front = temp->next;
		free(temp);

		if (d->front == NULL)
			d->rear = NULL;
		else
			d->front->prev = NULL;

		return return_data;
	}
}

node pop_rear(DEQUE* d)
{
	if (is_empty(d))
	{
		return;
	}
	else
	{
		node* temp = d->rear;
		node return_data;
		return_data.data = temp->data;
		return_data.idx = temp->idx;
		d->rear = temp->prev;
		free(temp);

		if (d->rear == NULL)
			d->front = NULL;
		else
			d->rear->next = NULL;

		return return_data;
	}
}


int main()
{
	int n;
	scanf("%d", &n);

	DEQUE d;
	init_DEQUE(&d);

	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		push_rear(&d, num, i + 1);
	}

	while (!is_empty(&d))
	{
		node temp = pop_front(&d);
		int value = temp.data;
		int idx = temp.idx;
		printf("%d ", idx);
		if (value > 0)
		{
			// 앞으로 밀어내기
			while (!is_empty(&d) && (value - 1) > 0)
			{
				temp = pop_front(&d);
				push_rear(&d, temp.data, temp.idx);
				value--;
			}
		}
		else
		{
			// 뒤로 밀어내기
			while (!is_empty(&d) && value < 0)
			{
				temp = pop_rear(&d);
				push_front(&d, temp.data, temp.idx);
				value++;
			}
		}
	}


	return 0;
}