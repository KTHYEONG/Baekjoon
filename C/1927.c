#include <stdio.h>  // �ּ� ��

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
		// ����, ������ ����
		if ((child < *ptr) && (heap[child] > heap[child + 1]))
		{
			child++;
		}

		// ���Ϸ��� �ڽ� ��尡 �̵���ų ������ ��庸�� ũ�� ���� 
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