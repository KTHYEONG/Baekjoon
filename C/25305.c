#include <stdio.h>  // 커트라인

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int arr[1000] = { 0, };
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	int temp;
	int j;
	for (int i = 1; i < n; i++)			// 삽입
	{
		temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] < temp; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
	/*for (int i = 0; i < n; i++)			// 버블
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}*/

	printf("%d", arr[k - 1]);


	return 0;
}