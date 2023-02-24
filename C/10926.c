#include <stdio.h> // ??!

int main()
{
	int i = 0;
	char input[50];
	scanf("%s", &input);
	while(input[i] != 0)
	{
		printf("%c", input[i]);
		i++;
	}
	printf("??!");

	return 0;
}