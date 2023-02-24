#include <stdio.h>  // 나이순 정렬
#include <stdlib.h>

typedef struct
{
	int age;
	int index;
	char name[101];
}list;

int compare(void* first, void* second)
{
	list* a = first;
	list* b = second;
	if (a->age > b->age)
		return 1;
	else if (a->age < b->age)
		return -1;
	else
	{
		if (a->index < b->index)
			return -1;
		else
			return 1;
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	list* arr;
	arr = (list*)malloc(n * sizeof(list));
	for (int i = 0; i < n; i++)
	{
		scanf("%d %s", &arr[i].age, &arr[i].name);
		arr[i].index = i;
	}

	qsort(arr, n, sizeof(arr[0]), compare);
	
	for (int i = 0; i < n; i++)
	{
		printf("%d %s\n", arr[i].age, arr[i].name);
	}

	return 0;
}