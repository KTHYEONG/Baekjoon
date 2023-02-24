/* #include <stdio.h>  // 부녀회장이 될테야

int main()
{
	int arr[15][15] = { 0, };
	for (int i = 0; i < 15; i++)
	{
		arr[0][i] = i;
	}

	for (int i = 1; i < 15; i++)
	{
		for (int j = 1; j < 15; j++)
		{
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}

	int T;
	scanf("%d", &T);

	int k, n;
	for (int i = 0; i < T; i++)
	{
		scanf("%d\n%d", &k, &n);
		printf("%d\n", arr[k][n]);
	}

	return 0;
} */

#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);

	int arr[15][15] = {0,};
	for (int i = 0; i < 15; i++)
	{
		arr[0][i] = i;
	}

	for (int i = 1; i < 15; i++)
	{
		for (int j = 1; j < 15; j++)
		{
			arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
		}

	}

	int k, n;
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &k);
		scanf("%d", &n);
		printf("%d\n", arr[k][n]);
	}

	return 0;
}