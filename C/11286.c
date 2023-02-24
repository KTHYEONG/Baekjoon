#include <stdio.h>  // 절댓값 힙
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

	while (i != 1 && (abs(num) <= abs(h->arr[i / 2].data)))
	{
		// 절댓값이 같을 경우 처리(더 작은 숫자가 이진트리 구조에서 위로 가야함)
		if (abs(num) == abs(h->arr[i / 2].data) && (num > h->arr[i / 2].data))
			break;
		h->arr[i].data = h->arr[i / 2].data;
		i /= 2;
	}
	h->arr[i].data = num;
}

int pop(HEAP* h)
{
	node root, temp;
	root.data = h->arr[1].data;
	temp.data = h->arr[(h->size)--].data;

	int parent = 1;
	int child = 2;

	while (child <= h->size)
	{
		if (child < h->size)
		{
			if ((abs(h->arr[child].data) > abs(h->arr[child + 1].data)))
			{
				child++;
			}
			// 절댓값이 같을 경우 처리
			else if ((abs(h->arr[child].data) == abs(h->arr[child + 1].data)) && h->arr[child].data > h->arr[child + 1].data)
			{
				child++;
			}
		}

		if (abs(temp.data) < abs(h->arr[child].data))
		{
			break;
		}
		else if (abs(temp.data) == abs(h->arr[child].data) && temp.data < h->arr[child].data)
		{
			break;
		}

		h->arr[parent].data = h->arr[child].data;
		parent = child;
		child *= 2;
	}
	h->arr[parent].data = temp.data;

	return root.data;
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
		if (num == 0 && h.size == 0)
		{
			printf("%d\n", 0);
		}
		else if (num == 0 && h.size != 0)
		{
			printf("%d\n", pop(&h));
		}
		else
		{
			push(&h, num);
		}
	}

	return 0;
}