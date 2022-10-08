#include <stdio.h> // 주사위 세개

int main()
{
	int a, b, c, sum, big;

	scanf("%d %d %d", &a, &b, &c);

	if (a == b && b == c && c == a)
	{
		sum = 10000 + a * 1000;
	}
	else if (a == b || b == c || c == a)
	{
		if (a == b)
			sum = 1000 + a * 100;
		else if (b == c)
			sum = 1000 + b * 100;
		else
			sum = 1000 + c * 100;
	}
	else
	{
		if (a > b && a > c)
			big = a;
		else if (b > a && b > c)
			big = b;
		else
			big = c;

		sum = big * 100;
	}

	printf("%d", sum);

	return 0;
}