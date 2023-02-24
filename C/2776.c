#include <stdio.h>  // ¾Ï±â¿Õ
#include <stdlib.h>

int n, m;
int arr[1000001];
int sort[1000001];

void merge(int* arr, int start, int mid, int end)
{
	int i, j, k;
	i = start;
	j = mid + 1;
	k = start;

	while (i <= mid && j <= end)
	{
		if (arr[i] >= arr[j])
			sort[k++] = arr[j++];
		else
			sort[k++] = arr[i++];
	}

	if (i > mid)
	{
		for (int idx = j; idx <= end; idx++)
		{
			sort[k++] = arr[idx];
		}
	}
	else
	{
		for (int idx = i; idx <= mid; idx++)
		{
			sort[k++] = arr[idx];
		}
	}

	for (int idx = start; idx <= end; idx++)
	{
		arr[idx] = sort[idx];
	}
}

void merge_sort(int* arr, int start, int end)
{
	int mid;
	if (start < end)
	{
		mid = (start + end) / 2;
		merge_sort(arr, start, mid);
		merge_sort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

int binary_search(int* arr, int num)
{
	int left = 0;
	int right = n;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] == num)
			return 1;
		else if (arr[mid] > num)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return 0;
}


int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[j]);
		}

		merge_sort(arr, 0, n);

		scanf("%d", &m);
		int num;
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &num);
			printf("%d\n", binary_search(arr, num));
		}

		for (int j = 0; j < n; j++)
		{
			arr[j] = 0;
		}
	}

	return 0;
}