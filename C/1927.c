#include <stdio.h>  // 최소 힙

int heap[100001];

void push(int num, int *ptr)
{
	int i = 0;
	i = ++(*ptr);

	while (i != 1 && num < heap[i / 2])
	{
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = num;
}

int pop(int *ptr)
{
	int root, temp;
	root = heap[1];
	temp = heap[(*ptr)--];
	int parent = 1;
	int child = 2;

	while (child <= *ptr)
	{
		// 왼쪽, 오른쪽 선택
		if ((child < *ptr) && (heap[child] > heap[child + 1]))
		{
			child++;
		}

		// 비교하려는 자식 노드가 이동시킬 마지막 노드보다 크면 종료 
		if (temp <= heap[child])
		{
			break;
		}

		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;

	return root;
}

int main()
{
	int n;
	scanf("%d", &n);

	int ptr = 0;
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);

		if (num == 0 && ptr != 0)
		{
			printf("%d\n", pop(&ptr));
		}
		else if (num == 0 && ptr == 0)
		{
			printf("%d\n", 0);
		}
		else
		{
			push(num, &ptr);
		}
	}

	return 0;
}