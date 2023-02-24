#include <stdio.h>  // 알고리즘 수업 - 병합 정렬 1

int count = 0;
int check = 0;

int merge(int arr[], int left, int mid, int right, int k2)
{
	int temp[right + 2];
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	
	if (i > mid)
	{
		for (l = j; l <= right; l++)
			temp[k++] = arr[l];
	}
	else
	{
		for (l = i; l <= mid; l++)
			temp[k++] = arr[l];
	}
	

	for (l = left; l <= right; l++)
	{
		arr[l] = temp[l];
		if (++count == k2)
		{
			printf("%d", arr[l]);
			check = 1;
		}
	}
}

int mergesort(int arr[], int left, int right, int k2)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		mergesort(arr, left, mid, k2);
		mergesort(arr, mid + 1, right, k2);
		merge(arr, left, mid, right, k2);
	}
}


int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int arr[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	mergesort(arr, 0, n - 1, k);
	if (check != 1)
		printf("%d", -1);

	return 0;
}