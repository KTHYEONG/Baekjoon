/*#include <stdio.h>  // 소수 찾기

int main()
{
	int n;
	scanf("%d", &n);

	int arr[1000] = { 0, }, count = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++)
	{
		int check = 0;
		if (arr[i] == 1)
			continue;
		else
		{
			for (int j = 2; j < arr[i]; j++)			// 2부터 1씩 증가하면서 입력 받은 값의 약수인지 확인(소수 판별)
			{
				if (arr[i] % j == 0)
				{
					check = 1;
					break;
				}
			}
		}
		if (check == 0)
			count++;
	}

	printf("%d", count);

	return 0;
}*/

#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int num, count = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		for (int j = 2; j <= num; j++)
		{
			if (num == j)
				count++;

			if (num % j == 0)
				break;
		}
	}

	printf("%d", count);

	return 0;
}