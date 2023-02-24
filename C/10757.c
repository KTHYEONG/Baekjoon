#include <stdio.h>  // ū �� A + B
#include <string.h>

void reverse(char arr[])
{
	int len = strlen(arr);
	char temp;
	for (int i = 0; i < len / 2; i++)
	{
		temp = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = temp;
	}
}


int main()			// c��� ū �� ��� --> ���ڸ� ���ڿ��� ������ �Ųٷ� ������ ���¸� ���
{
	char a[10002] = { 0, }, b[10002] = { 0, }, rev[10003] = { 0, };
	scanf("%s %s", a, b);

	reverse(a);
	reverse(b);

	int a_len = strlen(a), b_len = strlen(b);
	int max_len = a_len > b_len ? a_len : b_len;

	int sum = 0, flag = 0;
	for (int i = 0; i < max_len; i++)
	{
		sum = a[i] - '0' + b[i] - '0' + flag;
		if (sum < 0)			// a�� b �� ���� �ڸ����� �ٸ� ���
			sum += '0';

		if (sum > 9)			// ���� 9 ������ ���� �ڸ��� +1
			flag = 1;
		else
			flag = 0;
		rev[i] = sum % 10 + '0';			// ���� -- > ���� ���·� ����
	}
	if (flag == 1)			// ������ ����(�������� �� ó��)�� 1 �߰�
		rev[max_len] = '1';


	reverse(rev);			// ������ �迭�� �����·� ����
	printf("%s", rev);

	return 0;
}