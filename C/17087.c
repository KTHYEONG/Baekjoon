#include <stdio.h>  // ¼û¹Ù²ÀÁú 6
#include <stdlib.h>

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}


int main()
{
	int n, s;
	scanf("%d %d", &n, &s);

	int arr[100000];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		arr[i] = abs(arr[i] - s);
	}

	if (n == 1)
		printf("%d", arr[0]);
	else if (n == 2)
		printf("%d", gcd(arr[0], arr[1]));
	else
	{
		int result = gcd(arr[0], arr[1]);
		for (int i = 2; i < n; i++)
		{
			result = gcd(result, arr[i]);
		}
		printf("%d", result);
	}

	return 0;
}