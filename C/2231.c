/* #include <stdio.h>  // ºÐÇØÇÕ

int main()
{
	int n;
	scanf("%d", &n);

	int num, result = 0;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		num = i;
		while (num != 0)
		{
			sum += num % 10;
			num /= 10;
		}

		if (sum + i == n)
		{
			result = i;
			break;
		}
	}

	printf("%d", result);

	return 0;
} */

#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int result = 0;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		int num = i;
		while (num != 0)
		{
			sum += num % 10;
			num /= 10;
		}
		if (sum + i == n)
		{
			result = i;
			break;
		}
	}

	printf("%d", result);

	return 0;
}