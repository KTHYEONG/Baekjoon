#include <stdio.h>  // 달팽이는 올라가고 싶다

int main()
{
	int A, B, V, n;
	scanf("%d %d %d", &A, &B, &V);

	if ((V - A) % (A - B) == 0)
	{
		n = (V - A) / (A - B) + 1;
	}
	else         //(V - A) / (A - B) == 소수일 경우
	{
		n = (V - A) / (A - B) + 2;
	}

	printf("%d", n);

	return 0;
}