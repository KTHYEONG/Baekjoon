#include <stdio.h>  // 랜선 자르기
#include <stdlib.h>

int arr[10001] = { 0, };

long long binary_search(int max, int k, int n)
{
	long long left = 1, right = max, cut_max = 0;
	long long mid;
	while (left <= right)
	{
		mid = (left + right) / 2;

		int cnt = 0;
		for (int i = 0; i < k; i++)
		{
			cnt += arr[i] / mid;
		}

		if (cnt >= n)
		{
			if (cut_max < mid)
				cut_max = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return cut_max;
}


int main()
{
	int k, n;
	scanf("%d %d", &k, &n);

	int max = 0;
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] > max)
			max = arr[i];
	}

	printf("%lld", binary_search(max, k, n));

	return 0;
}