#include <stdio.h>  // ¼ö Ã£±â
#include <stdlib.h>

int compare(void* first, void* second)
{
	int* a = first;
	int* b = second;
	if (*a > * b)
		return 1;
	else if (*a < *b)
		return -1;
	else
		return 0;
}

int binary_search(int* sort, int num, int n)
{
	int low = 0, high = n - 1;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (num == sort[mid])
			return 1;
		else if (num > sort[mid])
			low = mid + 1;
		else if (num < sort[mid])
			high = mid - 1;
	}
	return 0;
}

int main()
{
	int n;
	scanf("%d", &n);

	int sort[100000];
	for (int i = 0; i < n; i++)
		scanf("%d", &sort[i]);

	qsort(sort, n, sizeof(sort[0]), compare);

	int m;
	scanf("%d", &m);

	int num;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &num);
		if (binary_search(sort, num, n))
			printf("%d\n", 1);
		else
			printf("%d\n", 0);
	}

	return 0;
}