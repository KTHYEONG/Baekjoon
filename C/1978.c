/*#include <stdio.h>  // �Ҽ� ã��

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
			for (int j = 2; j < arr[i]; j++)			// 2���� 1�� �����ϸ鼭 �Է� ���� ���� ������� Ȯ��(�Ҽ� �Ǻ�)
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