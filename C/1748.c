#include <stdio.h>  // �� �̾� ���� 1


int main()
{
	int n;
	scanf("%d", &n);

	int answer = 0;
	for (int i = 1; i <= n; i *= 10)
	{
		answer += n - i + 1;
	}

	printf("%d", answer);

	return 0;
}