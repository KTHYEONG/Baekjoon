#include <stdio.h>  // ¼Ò¼ö

int main()
{
	int M, N;
	scanf("%d\n%d", &M, &N);

	int sum = 0, min = 10000, check;
	for (int i = M; i <= N; i++)
	{
		check = 0;
		if (i == 1)
		{
			continue;
		}

		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				check = 1;
				break;
			}
		}
		if (check == 0)
		{
			if (i < min)
				min = i;
			sum += i;
		}
	}

	if (sum != 0)
		printf("%d\n%d", sum, min);
	else
		printf("%d", -1);

	return 0;
}