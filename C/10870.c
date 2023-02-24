#include <stdio.h>  // 피보나치 수 5

int fibo(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
	{
		return fibo(n - 1) + fibo(n - 2);
	}
}


int main()
{
	int n;
	scanf("%d", &n);

	int result = fibo(n);
	printf("%d", result);

	return 0;
}