/*#include <stdio.h>  // GCD 합(최대공약수 개념 복습)

int gcd(int a, int b)			// 유클리드 호제법
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}


int main()
{
	int t;
	scanf("%d", &t);

	int n;
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);

		int arr[100];
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[j]);

		long long int sum = 0;
		for (int k = 0; k < n - 1; k++)
		{
			for (int l = k + 1; l < n; l++)
			{
				sum += gcd(arr[k], arr[l]);
			}
		}

		printf("%lld\n", sum);

	}

	return 0;
}*/

#include <stdio.h>

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}


int main()
{
	int t;
	scanf("%d", &t);

	int arr[100];
	long long int sum = 0;
	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);

		for (int j = 0; j < n; j++)
			scanf("%d", &arr[j]);

		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				sum += gcd(arr[i], arr[j]);
			}
		}
		printf("%lld\n", sum);
		sum = 0;
	}

	return 0;
}