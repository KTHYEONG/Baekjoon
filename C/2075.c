#include <stdio.h>  // N번째 큰 수
#include <stdlib.h>

typedef struct
{
	int data;
}node;

typedef struct
{
	node arr[1500 * 1500 + 1];
	int size;
}HEAP;

HEAP h;

void push(int data)
{
	int i = ++(h.size);

	while ((i != 1) && (data > h.arr[i / 2].data))
	{
		h.arr[i].data = h.arr[i / 2].data;
		i /= 2;
	}
	h.arr[i].data = data;
}

int pop()
{
	int root, temp;
	root = h.arr[1].data;
	temp = h.arr[(h.size)--].data;

	int parent = 1;
	int child = 2;
	while (child <= h.size)
	{
		// 더 큰 숫자를 위로 올려주기위한 왼쪽, 오른쪽 선택
		if ((child < h.size) && (h.arr[child].data < h.arr[child + 1].data))
		{
			child++;
		}

		if (temp >= h.arr[child].data)
			break;

		h.arr[parent].data = h.arr[child].data;
		parent = child;
		child *= 2;
	}
	h.arr[parent].data = temp;

	return root;
}


int main()
{
	int n;
	scanf("%d", &n);
	
	h.size = 0;

	int num;
	for (int i = 0; i < n * n; i++)
	{
		scanf("%d", &num);
		push(num);
	}

	while (h.size > n * n - n + 1)
	{
		pop();
	}
	printf("%d", pop());


	return 0;
}