#include <stdio.h>  // �ִ������� �ּҰ����

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	int result = 0;
	for (int i = 1; i <= a && i <= b; i++)
	{
		if (a % i == 0 && b % i == 0)
			result = i;
	}

	printf("%d\n", result);
	printf("%d", (a * b) / result);

	return 0;
}