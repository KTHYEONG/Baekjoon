#include <stdio.h>  // 공유기 설치
#include <stdlib.h>

int arr[200001];

int compare(void* first, void* second)
{
	int* a = (int*)first;
	int* b = (int*)second;
	if (*a > *b)
		return 1;
	else if (*a < *b)
		return -1;
	else
		return 0;
}

int binary_search(int n, int c)
{
	// 최소간격 - left, 최대간격 - right
	int left = 0, right = arr[n - 1] - arr[0];
	int result = 0;
	while (left <= right)
	{
		int cnt = 1;
		int mid = (left + right) / 2;
		int start = arr[0];

		for (int i = 1; i < n; i++)
		{
			int temp = arr[i];
			if ((temp - start) >= mid)
			{
				cnt++;
				start = temp;
			}
		}

		// 공유기를 더 많이 설치함 --> 최대 간격이 아님 --> left 범위 증가
		if (cnt >= c)
		{
			result = mid;
			left = mid + 1;
		}
		// 공유기를 더 적게 설치함 --> 조건 만족 x --> right 범위 축소
		else
		{
			right = mid - 1;
		}
	}
	return result;
}


int main()
{
	int n, c;
	scanf("%d %d", &n, &c);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	qsort(arr, n, sizeof(arr[0]), compare);

	printf("%d", binary_search(n, c));


	return 0;
}