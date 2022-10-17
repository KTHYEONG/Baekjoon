#include <stdio.h>  // ÇÑ¼ö

int a(int N)
{
	int count = 0;
	if (N < 100)
		return N;
	else
	{
		count = 99;
		for (int i = 100; i <= N; i++)
		{
			int q_100 = i / 100;
			int w_10 = (i / 10) % 10;
			int e_1 = i % 10;

			if ((q_100 - w_10) == (w_10 - e_1))
				count++;
		}
		return count;
	}
}

int main()
{
	int N, result;
	scanf("%d", &N);

	result = a(N);
	printf("%d", result);

	return 0;
}