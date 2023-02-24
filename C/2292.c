#include <stdio.h>  // ¹úÁý

int main()
{
	int N;
	scanf("%d", &N);

	int count = 1;
	if (N > 7)
	{
		count++;
		int i = 6;
		for (int j = 8; j <= N; j+= i)
		{
			count++;
			i += 6;
		}
	}
	else if (N != 1)
		count++;
	
	printf("%d", count);

	return 0;
}