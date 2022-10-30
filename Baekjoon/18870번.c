#include <stdio.h>  // 좌표 압축  // 정렬(오름차순), 좌표 압축, 정렬(입력순)
#include <stdlib.h>

typedef struct
{
	int x1;
	int x2;
	int index;
}list;

int compare1(void* first, void* second)
{
	list *a = (list*)first;
	list *b = (list*)second;
	if (a->x1 > b->x1)
		return 1;
	else if (a->x1 < b->x1)
		return -1;
	else
		return 0;
}

int compare2(void* first, void* second)
{
	list* a = (list*)first;
	list* b = (list*)second;
	if (a->index > b->index)
		return 1;
	else if (a->index < b->index)
		return -1;
	else
		return 0;
}

int main()
{
	int n;
	scanf("%d", &n);

	list* arr;
	arr = (list*)malloc(n * sizeof(list));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i].x1);
		arr[i].index = i;
	}

	qsort(arr, n, sizeof(arr[0]), compare1);			// 정렬(오름차순)

	for (int i = 0; i < n; i++)			// 좌표 압축
	{
		if (i == 0)
			arr[i].x2 = 0;
		else
		{
			if (arr[i].x1 == arr[i - 1].x1)
				arr[i].x2 = arr[i - 1].x2;
			else
				arr[i].x2 = arr[i - 1].x2 + 1;
		}
	}

	qsort(arr, n, sizeof(arr[0]), compare2);			// 정렬(입력순)

	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i].x2);
	}

	return 0;
}