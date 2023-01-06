#include <stdio.h>  // 모든 순열
#include <stdlib.h>

int check[9] = { 0, };

void permutation(int *arr, int cnt, int n)
{
	if (cnt == n)
	{
		for (int i = 0; i < n; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (check[i] == 0)
			{
				check[i] = 1;
				arr[cnt] = i;
				permutation(arr, cnt + 1, n);
				check[i] = 0;
			}
		}
	}
}


int main()
{
	int n;
	scanf("%d", &n);

	int* arr = (int*)malloc(sizeof(int) * n);

	permutation(arr, 0, n);

	return 0;
}