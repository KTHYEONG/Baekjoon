#include <stdio.h>  // С§Че
#include <string.h>

int ans = 0;

void bitmask(char* input)
{
	int x;
	if (strcmp(input, "add") == 0)
	{
		scanf("%d", &x);
		ans |= (1 << x);
	}
	else if (strcmp(input, "remove") == 0)
	{
		scanf("%d", &x);
		ans &= ~(1 << x);
	}
	else if (strcmp(input, "check") == 0)
	{
		scanf("%d", &x);
		if ((ans & (1 << x)) > 0)
			printf("%d\n", 1);
		else
			printf("%d\n", 0);

	}
	else if (strcmp(input, "toggle") == 0)
	{
		scanf("%d", &x);
		ans ^= (1 << x);
	}
	else if (strcmp(input, "all") == 0)
	{
		ans = (1 << 22) - 1;
	}
	else
	{
		ans = 0;
	}
}


int main()
{
	int m;
	scanf("%d", &m);

	char input[7];
	for (int i = 0; i < m; i++)
	{
		scanf("%s", input);
		bitmask(input);
	}

	return 0;
}