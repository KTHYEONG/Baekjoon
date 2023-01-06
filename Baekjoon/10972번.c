#include <stdio.h>  // 다음 순열
#include <stdlib.h>

void next_permutation(int *arr, int n)
{
	int i = n - 1, j = n - 1, k = n - 1;

	while (i > 0 && arr[i - 1] >= arr[i])			// 내림차순 조사
		i--;

	if (i <= 0)							
		printf("%d", -1);
	else
	{
		while (arr[i - 1] >= arr[j])
			j--;

		int temp;
		temp = arr[i - 1];
		arr[i - 1] = arr[j];
		arr[j] = temp;

		while (i < k)
		{
			temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
			i++; k--;
		}
		
		for (int i = 0; i < n; i++)
			printf("%d ", arr[i]);
	}
}


int main()
{
	int n;
	scanf("%d", &n);

	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	next_permutation(arr, n);

	return 0;
}