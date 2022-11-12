#include <stdio.h>  // 최소공배수

int gcd(int a, int b)
{
	int c;
	while (b)
	{ 
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

int main()
{
	int n;
	scanf("%d", &n);

	int a, b, c;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		c = gcd(a, b);
		printf("%d\n", (a * b) / c);
	}
	

	return 0;
}