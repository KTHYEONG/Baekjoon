#include <stdio.h>  // ���� N���� ��

long long sum(int *a, int n)
{
	int SUM = 0;
	for (int i = 0; i < n; i++)
	{
		SUM += a[i];
	}

	return SUM;
}