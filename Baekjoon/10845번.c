#include <stdio.h>  // 큐 // 연결 리스트 복습(개념, 구현)
#include <stdlib.h>
#include <string.h>

/*typedef struct
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
	return q->count == 0;
}

void en_queue(queue* q, int data)
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

int de_queue(queue* q)
{
	int data;
	node* ptr;
	if (is_empty(q))
		return 0;
	ptr = q->front;
	data = ptr->data;
	q->front = ptr->next;
	free(ptr);
	q->count--;

	return data;
}


int main()
{
	queue q;
	init_queue(&q);

	for (int i = 1;i <= 10; i++)
	{
		en_queue(&q, i);
	}
	while (!is_empty(&q))  // 큐가 빌 때까지 
	{
		printf("%d ", de_queue(&q));  //큐에서 꺼내온 값 출력
	}
	printf("\n");


	return 0;
}*/

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

void push(queue* q, int data)
{
	node* newnode = (node*)malloc(sizeof(node));
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

		return data;
	}
}

int size(queue* q)
{
	return q->count;
}

int front(queue* q)
{
	return q->front->data;
}

int back(queue* q)
{
	return q->rear->data;
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
			printf("%d\n", pop(&q));
		else if (!strcmp(str, "size"))
			printf("%d\n", size(&q));
		else if (!strcmp(str, "empty"))
			printf("%d\n", is_empty(&q));
		else if (!strcmp(str, "front"))
		{
			if (is_empty(&q))
				printf("%d\n", -1);
			else
				printf("%d\n", front(&q));
		}
		else if (!strcmp(str, "back"))
			if (is_empty(&q))
				printf("%d\n", -1);
			else
				printf("%d\n", back(&q));
	}

	return 0;
}