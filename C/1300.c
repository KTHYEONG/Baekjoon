#include <stdio.h>  // K��° ��
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
			// mid / i or ��� �������(n��)
			cnt += min(mid / i, n);
		}

		// �������� ��ǥ���� �������
		// mid���� �� ū ���� �����ϱ� ���ؼ� left �� ����
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