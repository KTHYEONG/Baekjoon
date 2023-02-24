#include <stdio.h>  // 수 정렬하기 3

int main()
{
	int n;
	scanf("%d", &n);


	int counting[10001] = { 0, }, num;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		counting[num]++;
	}	

	for (int i = 0; i < 10001; i++)
	{
		if (counting[i] == 0)
			continue;
		for (int j = 0; j < counting[i]; j++)
		{
			printf("%d\n", i);
		}
	}

	return 0;
}