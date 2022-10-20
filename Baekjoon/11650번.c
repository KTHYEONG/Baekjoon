#include <stdio.h>  // 좌표 정렬하기
#include <stdlib.h>

typedef struct
{
	int x;
	int y;
}x_y;

int compare(void* first, void* second)
{
	x_y* a = (x_y*)first;
	x_y* b = (x_y*)second;

	if (a->x > b->x)
		return 1;
	else if (a->x < b->x)
		return -1;
	else
	{
		if (a->y > b->y)
			return 1;
		else
			return -1;
	}

	return 0;
}

int main()
{
	int n;
	scanf("%d", &n);

	x_y* arr;
	arr = (x_y*)malloc(n * sizeof(x_y));

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}
	
	qsort(arr, n, sizeof(arr[0]), compare);

	for (int i = 0; i < n; i++)
	{
		printf("%d %d\n", arr[i].x, arr[i].y);
	}

	return 0;
}