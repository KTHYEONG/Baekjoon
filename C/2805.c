#include <stdio.h>  // 나무 자르기

int arr[1000001] = { 0, };

int binary_search(int end, int n, int m)
{
	int min, max, mid = 0, cut_max = 0;
	min = 1;
	max = end;
	while (min <= max)
	{
		mid = (min + max) / 2;

		long long sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] > mid)
				sum += (long long)(arr[i] - mid);
		}
		if (sum < m)
		{
			max = mid - 1;
		}
		else
		{
			if (cut_max < mid)
				cut_max = mid;
			min = mid + 1;
		}
	}
	return cut_max;
}


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int min = 1000000001, max = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] > max)
			max = arr[i];
	}

	printf("%d", binary_search(max, n, m));
	

	return 0;
}