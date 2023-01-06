#include <stdio.h>  // 가장 긴 증가하는 부분 수열(lis)  // 개념 이해 다시
#include <stdlib.h>

int MAX(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}


int main()
{
	int n;
	scanf("%d", &n);

	int arr[1001];
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int lis[1001]; lis[0] = 1;
	for (int i = 1; i < n; i++)
	{
		lis[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				lis[i] = MAX(lis[i], lis[j] + 1);
			}
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (lis[i] > max)
			max = lis[i];
	}

	printf("%d", max);

	return 0;
}