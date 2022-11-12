#include <stdio.h>  // µ¦
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int data;
	struct node* next;
	struct node* prev;
}node;

typedef struct
{
	node* head;
	node* tail;
}Deque;

int is_empty(Deque *d)
{
	if (d->head == NULL)
		return 1;
	else
		return 0;
}

void push_front(Deque *d, int data)
{
	node* newnode = malloc(sizeof(node));
	newnode->data = data;
	newnode->next = d->head;

	if (is_empty(d))
		d->tail = newnode;
	else
		d->head->prev = newnode;

	newnode->prev = NULL;
	d->head = newnode;
}

void push_back(Deque* d, int data)
{
	node* newnode = malloc(sizeof(node));
	newnode->data = data;
	newnode->prev = d->tail;

	if (is_empty(d))
		d->head = newnode;
	else
		d->tail->next = newnode;

	newnode->next = NULL;
	d->tail = newnode;
}

int pop_front(Deque* d, int* count)
{
	if (is_empty(d))
		return -1;
	else
	{
		int data;
		node* pnode = d->head;
		data = d->head->data;

		d->head = d->head->next;
		free(pnode);

		if (d->head == NULL)
			d->tail = NULL;
		else
			d->head->prev = NULL;

		(*count)--;
		return data;
	}
}

int pop_back(Deque* d, int* count)
{
	if (is_empty(d))
		return -1;
	else
	{
		int data;
		node* pnode = d->tail;
		data = d->tail->data;

		d->tail = d->tail->prev;
		free(pnode);

		if (d->tail == NULL)
			d->head = NULL;
		else
			d->tail->next = NULL;

		(*count)--;
		return data;
	}
}

int front(Deque* d)
{
	if (is_empty(d))
		return -1;
	else
		return d->head->data;
}

int back(Deque* d)
{
	if (is_empty(d))
		return -1;
	else
		return d->tail->data;
}


int main()
{
	int n;
	scanf("%d", &n);

	Deque d;
	d.head = d.tail = NULL;

	int count = 0;
	char str[11];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		if (!strcmp(str, "push_front"))
		{
			int data;
			scanf("%d", &data);
			push_front(&d, data);
			count++;
		}
		else if (!strcmp(str, "push_back"))
		{
			int data;
			scanf("%d", &data);
			push_back(&d, data);
			count++;
		}
		else if (!strcmp(str, "pop_front"))
		{
			printf("%d\n", pop_front(&d, &count));
		}
		else if (!strcmp(str, "pop_back"))
		{
			printf("%d\n", pop_back(&d, &count));
		}
		else if (!strcmp(str, "size"))
		{
			printf("%d\n", count);
		}
		else if (!strcmp(str, "empty"))
		{
			printf("%d\n", is_empty(&d));
		}
		else if (!strcmp(str, "front"))
		{
			printf("%d\n", front(&d));
		}
		else if (!strcmp(str, "back"))
		{
			printf("%d\n", back(&d));
		}
	}

	return 0;
}