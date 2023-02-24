#include <stdio.h>  // ¿¹»ê

int binary_search(int low, int high, int*arr, int n, int m)
{
	int sum;
	int mid = (low + high) / 2;
	while (high >= low)
	{
		sum = 0;
		mid = (high + low) / 2;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] > mid)
			{
				sum += mid;
			}
			else
			{
				sum += arr[i];
			}
		}
		if (sum == m)
		{
			return mid;
		}
		else if (sum > m)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
		mid = (low + high) / 2;
	}
	return mid;
}


int main()
{
	int n;
	scanf("%d", &n);

	int arr[10000], max = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] > max)
			max = arr[i];
	}

	int m;
	scanf("%d", &m);

	printf("%d", binary_search(0, max, arr, n, m));

	return 0;
}