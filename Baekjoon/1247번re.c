#include <stdio.h>  // 부호  // 오버플로우 처리 방법 복습
#include <limits.h>

int main()
{
	long long num;
	for (int i = 0; i < 3; i++)
	{
		int n;
		scanf("%d", &n);

		long long sum = 0;
		int overflow = 0;
		for (int j = 0; j < n; j++)
		{
			scanf("%lld", &num);
			if (sum > 0 && num > 0 && sum > LLONG_MAX - num)
				overflow++;
			else if (sum < 0 && num < 0 && sum < LLONG_MIN - num)
				overflow--;
			sum += num;
		}

		if (overflow == 0)
		{
			if (sum > 0)
				printf("+\n");
			else if (sum < 0)
				printf("-\n");
			else
				printf("%d\n", 0);
		}
		else if (overflow > 0)
			printf("+\n");
		else
			printf("-\n");
	}

	return 0;
}