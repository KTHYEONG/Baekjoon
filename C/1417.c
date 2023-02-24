#include <stdio.h>  // 국회의원 선거
#include <stdlib.h>

typedef struct
{
	int data;
}node;

typedef struct
{
	node arr[50];
	int size;
}HEAP;

void push(HEAP* h, int data)
{
	int i;
	i = ++(h->size);

	while ((i != 1) && (data > h->arr[i / 2].data))
	{
		h->arr[i].data = h->arr[i / 2].data;
		i /= 2;
	}
	h->arr[i].data = data;
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
		if ((child < h->size) && (h->arr[child].data < h->arr[child + 1].data))
		{
			child++;
		}

		if (temp >= h->arr[child].data)
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

	int num1;
	scanf("%d", &num1);

	HEAP h;
	h.size = 0;

	for (int i = 0; i < n - 1; i++)
	{
		int data;
		scanf("%d", &data);
		push(&h, data);
	}

	int cnt = 0;
	while (1)
	{
		int POP = pop(&h);
		if (num1 > POP)
			break;
		if (POP >= num1)
		{
			num1++;
			POP--;
			cnt++;
			push(&h, POP);
		}
	}
	printf("%d", cnt);


	return 0;
}

/*#include <stdio.h>  // 국회의원 선거
#include <stdlib.h>

int compare(void* first, void* second)
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
	int n;
	scanf("%d", &n);

	int num1;
	scanf("%d", &num1);

	int max = 0, arr[50];
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d", &arr[i]);
	}

	int cnt = 0;
	while (1)
	{
		// 내림차순 정렬
		qsort(arr, n - 1, sizeof(int), compare);

		if (num1 > arr[0])
			break;

		// 가장 큰 수 -1, 기호 1번 +1
		num1 += 1;
		arr[0] -= 1;
		cnt++;
	}
	printf("%d", cnt);


	return 0;
}*/