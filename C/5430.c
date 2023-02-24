#include <stdio.h>  // AC
#include <stdlib.h>
#include <string.h>

typedef struct
{
	struct node* next;
	struct node* prev;
	int data;
}node;

typedef struct
{
	node* front;
	node* rear;
	int cnt;
}DEQUE;

int is_empty(DEQUE* d)
{
	if (d->cnt <= 0)
		return 1;
	else
		return 0;
}

void push_front(DEQUE* d, int data)
{
	node* newnode = malloc(sizeof(node));
	newnode->next = d->front;
	newnode->prev = NULL;
	newnode->data = data;

	if (is_empty(d))
	{
		d->rear = newnode;
	}
	else
	{
		d->front->prev = newnode;
	}
	d->front = newnode;
	d->cnt++;
}

void push_rear(DEQUE* d, int data)
{
	node* newnode = malloc(sizeof(node));
	newnode->next = NULL;
	newnode->prev = d->rear;
	newnode->data = data;

	if (is_empty(d))
	{
		d->front = newnode;
	}
	else
	{
		d->rear->next = newnode;
	}
	d->rear = newnode;
	d->cnt++;
}

int pop_front(DEQUE* d)
{
	if (is_empty(d))
		return -1;
	else
	{
		node* temp;
		temp = d->front;
		int data = temp->data;
		d->front = temp->next;

		if (d->front == NULL)
			d->rear = NULL;
		else
			d->front->prev = NULL;
		d->cnt--;
		free(temp);

		return data;
	}
}

int pop_rear(DEQUE* d)
{
	if (is_empty(d))
		return -1;
	else
	{
		node* temp;
		temp = d->rear;
		int data = temp->data;
		d->rear = temp->prev;

		if (d->rear == NULL)
			d->front = NULL;
		else
			d->rear->next = NULL;
		d->cnt--;
		free(temp);

		return data;
	}
}

void print_front(DEQUE* d)
{
	int check = d->cnt - 1;

	printf("[");
	while (!is_empty(d))
	{
		printf("%d", pop_front(d));
		if (check > 0)
			printf(",");
		check--;
	}
	printf("]\n");
}

void print_rear(DEQUE* d)
{
	int check = d->cnt - 1;

	printf("[");
	while (!is_empty(d))
	{
		printf("%d", pop_rear(d));
		if (check > 0)
			printf(",");
		check--;
	}
	printf("]\n");
}

char p[100001];


int main()
{
	int t;
	scanf("%d", &t);

	DEQUE d;
	d.front = d.rear = NULL;
	d.cnt = 0;

	for (int i = 0; i < t; i++)
	{
		int swap = 0, temp = 0;

		scanf("%s", p);
		int len = strlen(p);

		int n;
		scanf("%d", &n);
		getchar();

		char c;
		if (n != 0)
		{
			// '[' 버리기
			scanf(" %c", &c);

			for (int j = 0; j < n; j++)
			{
				int num;
				scanf("%d", &num);
				// ',' 및 ']' 버리기
				char trash;
				scanf("%c", &trash);

				push_rear(&d, num);
			}
		}
		else
		{
			// '[', ']' 받기
			scanf("%c %c", &c, &c);
		}
		
		for (int j = 0; j < len; j++)
		{
			if (p[j] == 'R')
			{
				swap = !swap;
			}
			else if (p[j] == 'D')
			{
				if (swap == 0)
				{
					temp = pop_front(&d);
				}
				else
				{
					temp = pop_rear(&d);
				}
			}
		}
		if (temp == -1)
			printf("error\n");
		else
		{
			if (swap == 0)
				print_front(&d);
			else
				print_rear(&d);
		}
	}

	return 0;
}