#include <stdio.h> // A + B - 4

int main()
{
	int A, B;
	while (scanf("%d %d", &A, &B) != EOF)
	{
		printf("%d\n", A + B);
	}

	return 0;
}