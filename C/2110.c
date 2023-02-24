#include <stdio.h>  // ������ ��ġ
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
	// �ּҰ��� - left, �ִ밣�� - right
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

		// �����⸦ �� ���� ��ġ�� --> �ִ� ������ �ƴ� --> left ���� ����
		if (cnt >= c)
		{
			result = mid;
			left = mid + 1;
		}
		// �����⸦ �� ���� ��ġ�� --> ���� ���� x --> right ���� ���
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