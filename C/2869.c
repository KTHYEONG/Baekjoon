#include <stdio.h>  // �����̴� �ö󰡰� �ʹ�

int main()
{
	int A, B, V, n;
	scanf("%d %d %d", &A, &B, &V);

	if ((V - A) % (A - B) == 0)
	{
		n = (V - A) / (A - B) + 1;
	}
	else         //(V - A) / (A - B) == �Ҽ��� ���
	{
		n = (V - A) / (A - B) + 2;
	}

	printf("%d", n);

	return 0;
}