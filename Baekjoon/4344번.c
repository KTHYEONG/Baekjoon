#include <stdio.h>  // 평균은 넘겠지

int main()
{
	int c, d, arr[1000];

	scanf("%d", &c);

	for (int i = 0; i < c; i++)
	{
		int sum = 0, avg = 0, count = 0;
		scanf("%d", &d);
		for (int j = 0; j < d; j++)
		{
			scanf("%d", &arr[j]);
			sum += arr[j];
		}
		avg = sum / d;
		
		for (int k = 0; k < d; k++)
		{
			if (avg < arr[k])
			{
				count++;
			}
		}
		printf("%.3f%%\n", (double)count / d * 100);
	}
	


	return 0;
}