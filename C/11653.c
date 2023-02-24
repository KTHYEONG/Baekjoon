#include <stdio.h>  // 소인수분해

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 2; i <= N; i++)
	{
		if (N % i == 0)
		{
			printf("%d\n", i);
			N /= i;
			i = 1;
		}
	}

	return 0;
}