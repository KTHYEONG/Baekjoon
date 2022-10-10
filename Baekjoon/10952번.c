#include <stdio.h> // A + B - 5

int main()
{
	int A = 1, B = 1;
	while (A != 0 && B != 0)
	{
		scanf("%d %d", &A, &B);
		if (A != 0 && B != 0)
			printf("%d\n", A + B);
	}


	return 0;
}