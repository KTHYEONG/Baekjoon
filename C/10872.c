#include <stdio.h>  // ÆÑÅä¸®¾ó

int fto(int n)
{
	if (n <= 1)
		return 1;
	else
	{
		return n * fto(n - 1);
	}
}


int main()
{
	int n;
	scanf("%d", &n);

	int result = fto(n);
	printf("%d", result);

	return 0;
}