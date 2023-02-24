/*#include <stdio.h> // 더하기 사이클

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
}*/

#include <stdio.h> // 더하기 사이클

int main()
{
	int n;
	scanf("%d", &n);

	int temp = n;
	int ans = 0;
	while (1)
	{
		int a = temp / 10;
		int b = temp % 10;
		int c = (a + b) % 10;
		int d = (b * 10) + c;
		temp = d;
		ans++;

		if (d == n)
			break;
	}
	printf("%d", ans);

	return 0;
}