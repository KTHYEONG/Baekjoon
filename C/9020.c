#include <stdio.h>  // �������� ����

int main()
{
	int arr[10001] = { 0, };
	arr[1] = 1;
	for (int i = 2; i < 10001; i++)			// �Ҽ� x -> 1�� �����ϴ� �迭 
	{
		for (int j = 2; i * j < 10001; j++)
		{
			arr[i * j] = 1;
		}
	}

	int T, n;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &n);
		for (int j = n / 2; j > 0; j--)			// n�� ���� �� --> ���� �ϰ� �� �� ���� ���� ���̰� ���� ������
		{
			if (arr[j] != 1 && arr[n - j] != 1)
			{
				printf("%d %d\n", j, n - j);
				break;
			}
		}

	}

	return 0;
}