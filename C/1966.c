#include <stdio.h>  // 프린터 큐
#include <stdlib.h>

typedef struct
{
	struct node* next;
	int data;
	int idx;
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

void push(queue* q, int data, int idx)
{
	node* newnode = malloc(sizeof(node));
	newnode->data = data;
	newnode->idx = idx;
	newnode->next = NULL;

	if (is_empty(q))
		q->front = newnode;
	else
		q->rear->next = newnode;
	q->rear = newnode;
	q->count++;
}

node pop(queue* q)
{
	node* ptr;
	node temp;
	if (is_empty(q))
		return;
	ptr = q->front;
	temp.data = ptr->data;
	temp.idx = ptr->idx;
	q->front = ptr->next;
	free(ptr);
	q->count--;

	return temp;
}

int FRONT(queue* q)
{
	return q->front->data;
}

int compare_(void* first, void* second)
{
	int* a = first;
	int* b = second;
	if (*a > *b)
		return -1;
	else if (*a < *b)
		return 1;
	else
		return 0;
}


int main()
{
	int t;
	scanf("%d", &t);

	int arr[100];
	for (int i = 0; i < t; i++)
	{
		int ans = 1, max = 0;

		queue q;
		init_queue(&q);

		int n, m;
		scanf("%d %d", &n, &m);
		for (int j = 0; j < n; j++)
		{	
			scanf("%d", &arr[j]);
			// 큐에 가중치 및 m값 저장하기
			if (j == m)
				push(&q, arr[j], m);
			else
				push(&q, arr[j], -1);
		}
		qsort(arr, n, sizeof(int), compare_);

		int k = 0;
		while (1)
		{
			node temp = pop(&q);
			if (arr[k] == temp.data)
			{
				if (temp.idx == m)
					break;
				k++;
				ans++;
			}
			else
			{
				// 뒤로 보내기
				push(&q, temp.data, temp.idx);
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}