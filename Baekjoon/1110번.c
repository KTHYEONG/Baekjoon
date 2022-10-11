#include <stdio.h> // 더하기 사이클

int main()
{
	int num, a, b, c, d = -1, result, N = 0;
	scanf("%d", &num);
	result = num;

	while (d != result)
	{
		a = num / 10;
		b = num % 10;
		c = (a + b) % 10;
		d = (b * 10) + c;
		num = d;
		N++;
	}

	printf("%d", N);

	return 0;
}