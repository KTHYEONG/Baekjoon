#include <stdio.h>  // N과 M (2)  // 코드 흐름 이해 다시(재귀)
#include <stdlib.h>

int check[9] = { 0, };

void permutation(int *arr, int cnt, int n, int m, int cut)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (check[i] == 0 && cut < i)
			{
				check[i] = 1;
				arr[cnt] = i;
				permutation(arr, cnt + 1, n, m, i);
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

	permutation(arr, 0, n, m, 0);

	return 0;
}


/*#include <stdio.h>  // N과 M (2)  // 코드 흐름 이해 다시(재귀)
#include <stdlib.h>

int check[9] = { 0, };

void permutation(int* arr, int cnt, int n, int m, int cut)
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
			if (check[i] == 0 && cut < i)
			{
				check[i] = 1;
				arr[cnt] = i;
				permutation(arr, cnt + 1, n, m, i);
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

	permutation(arr, 0, n, m, 0);

	return 0;
}*/