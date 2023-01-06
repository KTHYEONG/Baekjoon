#include <stdio.h>  // -2Áø¼ö

void trans(int n)
{
	if (n == 0)
		return 0;

	if (n % 2 == 0)
	{
		trans(-(n / 2));
		printf("0");
	}
	else
	{
		if (n > 0)
		{
			trans(-(n / 2));
		}
		else
		{
			trans((-n + 1) / 2);
		}
		printf("1");
	}
		
}


int main()
{
	int n;
	scanf("%d", &n);

	if (n == 0)
		printf("0");
	else
		trans(n);

	return 0;
}