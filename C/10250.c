#include <stdio.h>  // ACM хёез

int main()
{
	int t;
	scanf("%d", &t);

	int h, w, n;
	int arr[100][100];
	while (t)
	{
		scanf("%d %d %d", &h, &w, &n);

		int count = 0;
		for (int i = 1; i <= w; i++)
		{
			for (int j = 1; j <= h; j++)
			{
				arr[i - 1][j - 1] = j * 100 + i;
				count++;
				if (count == n)
				{
					printf("%d\n", arr[i - 1][j - 1]);
					break;
				}
			}
		}
		t--;
	}
	
	return 0;
}