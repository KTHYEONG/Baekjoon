#include <stdio.h>  // K번째 수
#include <stdlib.h>

#define min(a, b) a > b ? b : a

long long binary_search(long long n, long long k)
{
	long long left = 1, right = k;
	long long mid;
	long long ans = -1;
	while (left <= right)
	{
		mid = (left + right) / 2;

		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			// mid / i or 모두 작은경우(n개)
			cnt += min(mid / i, n);
		}

		// 작은값이 목표보다 적은경우
		// mid값을 더 큰 수로 설정하기 위해서 left 값 증가
		if (cnt < k)
		{
			left = mid + 1;
		}
		else
		{
			ans = mid;
			right = mid - 1;
		}
	}
	return ans;
}


int main()
{
	long long n;
	scanf("%lld", &n);

	long long k;
	scanf("%lld", &k);

	printf("%lld", binary_search(n, k));

	return 0;
}