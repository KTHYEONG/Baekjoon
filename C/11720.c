#include <stdio.h>  // 숫자의 합

int main()
{
	char str[100];
	int n;
	scanf("%d", &n);
	scanf("%s", str);

	int i = 0, sum = 0;
	while (n > 0)
	{
		sum += str[i] - '0';
		n--; i++;
	}

	printf("%d", sum);

	return 0;
}