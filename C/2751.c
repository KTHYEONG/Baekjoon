#include <stdio.h>  // 수 정렬하기 2
#include <stdlib.h>

int arr[1000000];

int compare(void* first, void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}


	qsort(arr, n, sizeof(int), compare);

	for (int i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}