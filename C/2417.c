#include <stdio.h>  // Á¤¼ö Á¦°ö±Ù
#include <math.h>

int main()
{
	long long int n;
	scanf("%lld", &n);

	long long int ans = (long long)sqrt(n);
	if (ans * ans < n)
		printf("%lld", ans + 1);
	else
		printf("%lld", ans);

	return 0;
}