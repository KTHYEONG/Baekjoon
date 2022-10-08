#include <stdio.h> // A/B

int main()
{
	double A, B;
	scanf("%lf %lf", &A, &B);
	printf("%.13lf", A / B);

	return 0;
}