#include <stdio.h>  // 분수 찾기

int main()
{
	int x;
	scanf("%d", &x);

	int i = 1;
	while (x > i)
	{
		x -= i;
		i++;
	}

	if (i % 2 == 1)
		printf("%d/%d", i + 1 - x, x);
	else
		printf("%d/%d", x, i + 1 - x);

	return 0;
}