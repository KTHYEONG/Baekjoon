#include <stdio.h>  // �׷� �ܾ� üĿ
#include <string.h>

int main()
{
	int N;
	scanf("%d", &N);

	int count = 0; char str[101];
	for (int i = 0; i < N; i++)
	{
		scanf("%s", str);

		int length = strlen(str);
		if (length <= 2)                                // ���� ���� 2���ϴ� ������ ����
			count++;
		else
		{
			int check = 0;
			for (int j = 0; j < length - 2; j++)
			{
				for (int k = j + 2; k < length; k++)    // 2��° �ڿ� �ִ� ���ں��� ������ ��ġ�ϴ°� �ִ��� ã�� 
				{
					if (str[j] == str[k] && str[j] != str[k - 1])
					{
						check = 1;
						break;
					}
				}
			}
			if (check == 0)
				count++;
		}
	}

	printf("%d", count);

	return 0;
}