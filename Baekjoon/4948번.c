#include <stdio.h>  // 베르트랑 공준

int main()
{
	int arr[249613] = { 0, };
	arr[1] = 1;
	for (int i = 2; i < 249613; i++)
	{
		for (int j = 2; i * j < 249613; j++)
		{
			arr[i * j] = 1;
		}
	}

	int n, n2, count = 0;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;

		n2 = 2 * n;
		for (int i = n + 1; i <= n2; i++)
		{
			if (arr[i] == 0)
				count++;
		}
		printf("%d\n", count);
		count = 0;
	}

	return 0;
}