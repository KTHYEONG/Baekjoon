#include <stdio.h>  // 숫자 카드(이진 탐색)

int input[500000];
int num[500000];
int sorted[500000];

void merge(int arr[], int start, int mid, int end)
{
	int i, j, k;
	i = start;
	j = mid + 1;
	k = start;

	while (i <= mid && j <= end)
	{
		if (arr[i] <= arr[j])
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}

	if (i > mid)
	{
		for (int idx = j; idx <= end; idx++)
			sorted[k++] = arr[idx];
	}
	else
	{
		for (int idx = i; idx <= mid; idx++)
			sorted[k++] = arr[idx];
	}

	for (int idx = start; idx <= end; idx++)
		arr[idx] = sorted[idx];
}

void merge_sort(int arr[], int start, int end)
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

int binary_search(int input[], int n, int num)
{
	int start = 0, end = n;
	int mid = (start + end) / 2;
	while (start <= end)
	{
		if (input[mid] == num)
			return 1;
		else if (input[mid] < num)
			start = mid + 1;
		else
			end = mid - 1;
		mid = (start + end) / 2;
	}
	return 0;
}


int main()
{
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &input[i]);

	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
		scanf("%d", &num[i]);

	merge_sort(input, 0, n - 1);

	for (int i = 0; i < m; i++)
	{
		if (binary_search(input, n, num[i]))
			printf("%d ", 1);
		else
			printf("%d ", 0);
	}

	return 0;
}