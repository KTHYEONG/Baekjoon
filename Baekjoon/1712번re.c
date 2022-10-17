#include <stdio.h>  // 손익분기점

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	int result = 0;
	if (c - b <= 0)
		result = -1;
	else
	{
		result = (a / (c - b)) + 1;
	}
	printf("%d", result);

	return 0;
}