#include <stdio.h>  // 카드 정렬하기
#include <stdlib.h>

typedef struct
{
	int data;
}node;

typedef struct
{
	node arr[100001];
	int size;
}HEAP;

void push(HEAP* h, int num)
{
	int i;
	i = ++(h->size);

	while ((i != 1) && num < h->arr[i / 2].data)
	{
		h->arr[i].data = h->arr[i / 2].data;
		i /= 2;
	}
	h->arr[i].data = num;
}

int pop(HEAP* h)
{
	int root, temp;
	root = h->arr[1].data;
	temp = h->arr[(h->size)--].data;

	int parent = 1;
	int child = 2;

	while (child <= h->size)
	{
		if ((child < h->size) && (h->arr[child].data > h->arr[child + 1].data))
		{
			child++;
		}

		if (temp <= h->arr[child].data)
			break;

		h->arr[parent].data = h->arr[child].data;
		parent = child;
		child *= 2;
	}
	h->arr[parent].data = temp;

	return root;
}


int main()
{
	int n;
	scanf("%d", &n);

	HEAP h;
	h.size = 0;

	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		push(&h, num);
	}

	long long int sum = 0;
	while (h.size > 1)
	{
		int a, b;
		a = pop(&h);
		b = pop(&h);
		sum += (a + b);
		push(&h, a + b);
	}
	printf("%lld", sum);


	return 0;
}