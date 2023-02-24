#include <stdio.h>  // 숫자 카드 2(lower, upper 이진 탐색)

int sort[500000];
int arr[500000];
int temp[500000];
int count[500000];

void merge(int *sort, int start, int mid, int end)
{
	int i, j, k;
	i = start, j = mid + 1, k = start;
	while (i <= mid && j <= end)
	{
		if (sort[i] >= sort[j])
			temp[k++] = sort[j++];
		else
			temp[k++] = sort[i++];
	}

	if (i > mid)
	{
		for (int idx = j; idx <= end; idx++)
			temp[k++] = sort[idx];
	}
	else
	{
		for (int idx = i; idx <= mid; idx++)
			temp[k++] = sort[idx];
	}

	for (int idx = start; idx <= end; idx++)
		sort[idx] = temp[idx];

}

void merge_sort(int *sort, int start, int end)
{
	int mid;
	if (start < end)
	{
		mid = (start + end) / 2;
		merge_sort(sort, start, mid);
		merge_sort(sort, mid + 1, end);
		merge(sort, start, mid, end);
	}
}

int lower_binary(int *sort, int num, int n)
{
	int mid, start, end;
	start = 0;
	end = n - 1;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (num <= sort[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return start;
}

int upper_binary(int* sort, int num, int n)
{
	int mid, start, end;
	start = 0;
	end = n - 1;
	while (end >= start)
	{
		mid = (start + end) / 2;
		if (num < sort[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return start;
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &sort[i]);

	merge_sort(sort, 0, n - 1);

	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		scanf("%d", &arr[i]);
		count[i] = 0;
	}

	int lower, upper;
	for (int i = 0; i < m; i++)
	{
		lower = lower_binary(sort, arr[i], n);
		upper = upper_binary(sort, arr[i], n);
		count[i] = upper - lower;
	}

	for (int i = 0; i < m; i++)
		printf("%d ", count[i]);

	return 0;
}