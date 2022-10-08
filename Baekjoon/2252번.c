#include <stdio.h> // ¿Àºì ½Ã°è

int main()
{
	int A, B, C;

	scanf("%d %d", &A, &B);
	scanf("%d", &C);

	if (B + C < 60)
		printf("%d %d", A, B + C);
	else
	{
		int h, m;
		h = (B + C) / 60;
		m = (B + C) % 60;
		if (A + h > 23)
			A = A + h - 24;
		else
			A += h;

		printf("%d %d", A, m);
	}

	return 0;
}