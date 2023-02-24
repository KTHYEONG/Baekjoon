#include <stdio.h>  // 분산처리


int main()
{
	int t;
	scanf("%d", &t);

	int a, b;
	for (int i = 0; i < t; i++)
	{
		scanf("%d %d", &a, &b);
		int c = 1;
		for (int j = 0; j < b; j++)
		{
			c *= a;
			c %= 10;
		}
		if (c == 0)
			printf("%d\n", 10);
		else
			printf("%d\n", c);
	}

	return 0;
}