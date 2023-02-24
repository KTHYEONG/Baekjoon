#include <stdio.h> // X보다 작은 수
#include <stdlib.h>


int main()
{
	int N, X;
	scanf("%d %d", &N, &X);

	int* arr = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] >= X)
		{
			arr[i] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (arr[i] != 0)
			printf("%d ", arr[i]);
	}

	free(arr);
	
	return 0;
}