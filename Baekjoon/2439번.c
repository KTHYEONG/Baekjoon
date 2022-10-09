#include <stdio.h> // º° Âï±â - 2

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < N - i; j++)
		{
			printf(" ");
		}

		for (int k = 0; k <= i; k++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}