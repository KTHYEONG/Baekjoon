#include <stdio.h>  // ЦђБе

int main()
{
	int n, max = 0, score[1000];
	double sum = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &score[i]);
		if (score[i] > max)
		{
			max = score[i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		sum += (double)score[i] / max * 100;
	}
	printf("%lf", sum / n);


	return 0;
}