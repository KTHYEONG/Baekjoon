#include <stdio.h>  // 팩토리얼 0의 개수(개념 복습)

int main()
{
	int n;
	scanf("%d", &n);

	int two = 0, five = 0;
	for (int i = 2; i <= n; i*=2)
	{
		two += n / i;
	}

	for (int i = 5; i <= n; i *= 5)
	{
		five += n / i;
	}

	printf("%d", (two > five) ? five : two);

	return 0;
}