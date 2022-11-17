#include <stdio.h>  // 조합 0의 개수

long long int i;

int count5(int num)
{
	int count = 0;
	for (i = 5; i <= num; i*=5)
	{
		count += num / i;
	}

	return count;
}

int count2(int num)
{
	int count = 0;
	for (i = 2; i <= num; i *= 2)
	{
		count += num / i;
	}

	return count;
}

int main()
{
	int n, r;
	scanf("%d %d", &n, &r);

	int two = 0, five = 0;

	five += count5(n);
	if (r != 0)
		five -= count5(r);
	if (n != r)
		five -= count5(n - r);

	two += count2(n);
	if (r != 0)
		two -= count2(r);
	if (n != r)
		two -= count2(n - r);

	if (five > two)
		printf("%d", two);
	else
		printf("%d", five);

	return 0;
}