#include <stdio.h>  // ¸ÔÀ» °ÍÀÎ°¡ ¸ÔÈú °ÍÀÎ°¡
#include <stdlib.h>

int arr_a[20000];
int arr_b[20000];

int compare(void* first, void* second)
{
	int* a = first;
	int* b = second;
	if (*a > *b)
		return 1;
	else if (*a < *b)
		return -1;
	else
		return 0;
}

int binary_search(int a_num, int* arr_b, int n, int m)
{
	int left = 0, right = m - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a_num > arr_b[mid])
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return left;
}


int main()
{
	int t;
	scanf("%d", &t);

	int n, m;
	for (int i = 0; i < t; i++)
	{
		scanf("%d %d", &n, &m);
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr_a[j]);
		}
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr_b[j]);
		}

		qsort(arr_b, m, sizeof(arr_b[0]), compare);

		int ans = 0;
		for (int j = 0; j < n; j++)
		{
			ans += binary_search(arr_a[j], arr_b, n, m);
		}
		printf("%d\n", ans);
	}

	return 0;
}