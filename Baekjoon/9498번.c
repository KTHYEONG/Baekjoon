#include <stdio.h> // 시험 성적

int main()
{
	int score;

	scanf("%d", &score);

	if (score >= 90 && score <= 100)
		puts("A");
	else if (score >= 80 && score <= 89)
		puts("B");
	else if (score >= 70 && score <= 79)
		puts("C");
	else if (score >= 60 && score <= 69)
		puts("D");
	else
		puts("F");

	return 0;
}