#include <stdio.h>  // ũ�ξ�Ƽ�� ���ĺ�
#include <string.h>

int main()
{
	char str[101];
	scanf("%s", str);

	int count = strlen(str);
	for (int i = 0; i < strlen(str); i++)                   // ��ü ���� - ũ�ξ�Ƽ�� ���ĺ�(ũ�ξ�Ƽ�� ���ĺ� ������ �Ѱ��� ���)
	{
		if (str[i] == '=')
		{
			if (str[i - 1] == 'c' || str[i - 1] == 's')
				count--;
			if (str[i - 1] == 'z')
			{
				count--;
				if (str[i - 2] == 'd')
					count--;
			}
		}
		if (str[i] == '-')
		{
			if (str[i - 1] == 'c' || str[i - 1] == 'd')
				count--;
		}

		if (str[i] == 'j')
		{
			if (str[i - 1] == 'l' || str[i - 1] == 'n')
				count--;
		}

	}

	printf("%d", count);

	return 0;
}