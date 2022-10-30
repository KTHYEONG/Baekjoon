#include <stdio.h>  // ÃÖ´ñ°ª

int main()
{
	int a[9][9];
	int max = -1;
	int idx1 = 0, idx2 = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%d ", &a[i][j]);
			if (a[i][j] > max)
			{
				max = a[i][j];
				idx1 = i + 1;
				idx2 = j + 1;
			}
		}
	}

	printf("%d \n", max);
	printf("%d %d", idx1, idx2);

	return 0;
}