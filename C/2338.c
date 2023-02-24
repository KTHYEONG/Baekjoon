#include <stdio.h>  // Çà·Ä µ¡¼À

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int a[100][100], b[100][100], c[100][100];

	for (int j = 0; j < n; j++)
	{
		for (int k = 0; k < m; k++)
		{
			scanf("%d", &a[j][k]);
		}
	}

	for (int j = 0; j < n; j++)
	{
		for (int k = 0; k < m; k++)
		{
			scanf("%d", &b[j][k]);
		}
	}

	for (int j = 0; j < n; j++)
	{
		for (int k = 0; k < m; k++)
		{
			c[j][k] = a[j][k] + b[j][k];
		}
	}

	for (int j = 0; j < n; j++)
	{
		for (int k = 0; k < m; k++)
		{
			printf("%d ", c[j][k]);
		}
		printf("\n");
	}

	return 0;
}