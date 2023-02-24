#include <stdio.h>  // 과제 안 내신 분..?

int main()
{
	int n[28];
	for (int i = 0; i < 28; i++)
	{
		scanf("%d", &n[i]);
	}
	
	for (int i = 1; i <= 30; i++)
	{
		int check = 0;
		for (int j = 0; j < 28; j++)
		{
			if (n[j] == i)
			{
				check++;
				break;
			}
		}
		if (check == 0)
			printf("%d\n", i);
	}

	return 0;
}