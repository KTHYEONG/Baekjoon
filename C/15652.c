#include <stdio.h>  // N°ú M (4)
#include <stdlib.h>

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
			if (cut <= i)
			{
				arr[cnt] = i;
				permutation(arr, cnt + 1, n, m, i);
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