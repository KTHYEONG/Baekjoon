#include <stdio.h>  // �ܾ��� ����
#include <string.h>

char str[1000001];

int main()
{
	scanf("%[^\n]s", str);        // ���� ���� ���ڿ� �Է¹ޱ�

	int count = 0;
	if (str[0] != ' ')			  // ù ���ڰ� ������ �ƴ� ���
		count++;

	for (int i = 1; i < strlen(str); i++)
	{
		if (str[i - 1] == ' ' && str[i] != ' ')
		{
			count++;
		}
	}

	printf("%d", count);

	return 0;
}