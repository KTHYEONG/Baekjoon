#include <stdio.h>  // �ٸ� ����


int main()  // ���� mCn ó�� factorial�� ���� --> ���� �ʹ� Ŀ���� ���� x
{
	int t;
	scanf("%d", &t);

	unsigned long long int combination[30][30];
	combination[1][0] = combination[1][1] = 1;
	for (int i = 2; i <= 29; i++)
	{
		combination[i][0] = 1;
		for (int j = 1; j < i; j++)
			combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];
		combination[i][i] = 1;
	}

	for (int i = 0; i < t; i++)
	{
		int n, m;
		scanf("%d %d", &n, &m);

		printf("%llu\n", combination[m][n]);
	}

	return 0;
}