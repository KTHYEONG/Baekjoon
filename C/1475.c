#include <stdio.h>  // ¹æ ¹øÈ£
#include <string.h>

char n[100001];

int main()
{
	scanf("%s", n);

	int arr[10] = { 0, };
	int len = strlen(n);
	for (int i = 0; i < len; i++)
	{
		arr[n[i] - '0']++;
	}
	arr[6] = (arr[6] + arr[9] + 1) / 2;

	int max = 0;
	for (int i = 0; i < 9; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	printf("%d", max);

	return 0;
}