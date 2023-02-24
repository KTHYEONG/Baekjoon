#include <stdio.h>  // ¼û¹Ù²ÀÁú
#include <stdlib.h>

#define min(a, b) a > b ? b : a 

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

void init_queue(queue* q)
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

int visit[100001] = { 0, };

void bfs(int num, int goal)
{
	queue q;
	init_queue(&q);
	push(&q, num);

	int cnt = 0;
	while (!is_empty(&q))
	{
		int q_size = q.count;
		for (int i = 0; i < q_size; i++)
		{
			int q_pop = pop(&q);
			if (q_pop == goal)
			{
				printf("%d", cnt);
				break;
			}

			if (q_pop - 1 >= 0 && q_pop - 1 <= 100000 && visit[q_pop - 1] == 0)
			{
				visit[q_pop - 1] = 1;
				push(&q, q_pop - 1);
			}
			if (q_pop + 1 >= 0 && q_pop + 1 <= 100000 && visit[q_pop + 1] == 0)
			{
				visit[q_pop + 1] = 1;
				push(&q, q_pop + 1);
			}
			if (q_pop * 2 >= 0 && q_pop * 2 <= 100000 && visit[q_pop * 2] == 0)
			{
				visit[q_pop * 2] = 1;
				push(&q, q_pop * 2);
			}
		}
		cnt++;
	}
}


int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	bfs(n, k);

	return 0;
}