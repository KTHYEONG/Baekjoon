#include <stdio.h>  // N°ú M (1)
#include <stdlib.h>

int check[1000] = { 0, };

void permutation(int *arr, int cnt, int n, int m)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (check[i] == 0)
			{
				arr[cnt] = i;
				check[i] = 1;
				permutation(arr, cnt + 1, n, m);
				check[i] = 0;
			}
		}
	}
}


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int* arr = (int*)malloc(sizeof(int) * m);

	permutation(arr, 0, n, m);

	return 0;
}