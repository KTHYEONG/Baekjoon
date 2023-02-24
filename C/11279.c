#include <stdio.h>  // ÃÖ´ë Èü

typedef struct
{
	int data;
}node;

typedef struct
{
	node arr[100001];
	int ptr;
}HEAP;

void push(HEAP* h, node input)
{
	int i;
	i = ++(h->ptr);

	while ((i != 1) && (input.data > h->arr[i / 2].data))
	{
		h->arr[i] = h->arr[i / 2];
		i /= 2;
	}
	h->arr[i] = input;
}

node pop(HEAP* h)
{
	node root, temp;
	root = h->arr[1];
	temp = h->arr[(h->ptr)--];

	int parent = 1;
	int child = 2;

	while (child <= h->ptr)
	{
		if ((child < h->ptr) && (h->arr[child].data < h->arr[child + 1].data))
		{
			child++;
		}

		if (temp.data >= h->arr[child].data)
		{
			break;
		}

		h->arr[parent] = h->arr[child];
		parent = child;
		child *= 2;
	}
	h->arr[parent] = temp;

	return root;
}


int main()
{
	int n;
	scanf("%d", &n);

	HEAP h;
	h.ptr = 0;

	for (int i = 0; i < n; i++)
	{
		node input;
		scanf("%d", &input.data);

		if (input.data == 0 && h.ptr != 0)
		{
			node ans = pop(&h);
			printf("%d\n", ans.data);
		}
		else if (input.data == 0 && h.ptr == 0)
		{
			printf("%d\n", 0);
		}
		else
		{
			push(&h, input);
		}
	}


	return 0;
}