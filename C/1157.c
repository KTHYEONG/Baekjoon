#include <stdio.h>  // �ܾ� ����
#include <string.h>

int arr[26];
char str[1000000];

int main()
{
	scanf("%s", str);
	int length = strlen(str);

	for (int i = 0; i < length; i++)        // a ~ Z ���� � �����ϴ��� �˻��ϱ�
	{
		if (str[i] >= 'a')
		{
			arr[str[i] - 'a']++;
		}
		else
		{
			arr[str[i] - 'A']++;
		}
	}

	int max = 0; char result;                    // ���� ���� ���� ���ĺ� ã��     
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] == max)
		{
			result = '?';
		}
		else if (arr[i] > max)
		{
			max = arr[i];
			result = 'A' + i;
		}
	}

	printf("%c", result);

	return 0;
}