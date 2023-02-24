#include <stdio.h>  // 카드 합체 놀이
#include <stdlib.h>

typedef struct
{
	long long data;
}node;

typedef struct
{
	node arr[1001];
	int size;
}HEAP;

void push(HEAP* h, long long data)
{
	int i;
	i = ++(h->size);
	while ((i != 1) && (data < h->arr[i / 2].data))
	{
		h->arr[i].data = h->arr[i / 2].data;
		i /= 2;
	}
	h->arr[i].data = data;
}

long long pop(HEAP* h)
{
	long long root, temp;
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
	int n, m;
	scanf("%d %d", &n, &m);
	
	HEAP h;
	h.size = 0;

	long long num;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &num);
		push(&h, num);
	}

	for (int i = 0; i < m; i++)
	{
		long long num1 = pop(&h);
		long long num2 = pop(&h);
		long long sum = num1 + num2;
		push(&h, sum);
		push(&h, sum);
	}

	long long ans = 0;
	while (h.size > 0)
	{
		ans += pop(&h);
	}
	printf("%lld", ans);


	return 0;
}

/*#include <stdio.h>  // 카드 합체 놀이
#include <stdlib.h>

int compare(void* first, void* second)
{
	long long int* a = first;
	long long int* b = second;
	if (*a > *b)
		return 1;
	else if (*a < *b)
		return -1;
	else
		return 0;
}


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	long long int arr[1001];
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);
	}

	for (int i = 0; i < m; i++)
	{
		// 오름차순 정렬
		qsort(arr, n, sizeof(long long int), compare);
		long long int sum = arr[0] + arr[1];
		arr[0] = arr[1] = sum;
	}

	long long int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += arr[i];
	}
	printf("%lld", ans);

	return 0;
}*/