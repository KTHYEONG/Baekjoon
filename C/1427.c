#include <stdio.h>  // ��Ʈ�λ��̵�
#include <stdlib.h>
#include <string.h>

int main()
{
	char n[11];
	gets(n);

	int counting[10] = { 0, };
	for (int i = 0; i < strlen(n); i++)
	{
		counting[n[i] - '0']++;
	}

	for (int i = 9; i >= 0; i--)
	{
		for (int j = 0; j < counting[i]; j++)
		{
			printf("%d", i);
		}
	}

	return 0;
}

/* #include <stdio.h>  // ��Ʈ�λ��̵�
#include <string.h>

int main()
{
	char n[11] = { NULL };			// ���� ���� ���ٷ� ���� �Է� ���� �� ���ڿ� �̿��ϱ�
	gets(n);

	int counting[10] = { 0, };			// ���
	for (int i = 0; i < strlen(n); i++)
	{
		counting[n[i] - '0']++;
	}

	for (int i = 9; i >= 0; i--)
	{
		for (int j = 0; j < counting[i]; j++)
		{
			printf("%d ", i);
		}
	}

	/* int j, temp;			  // ����
	for (int i = 1; i < strlen(n); i++)
	{
		temp = n[i];
		for (j = i - 1; j >= 0 && n[j] < temp; j--)
		{
			n[j + 1] = n[j];
		}
		n[j + 1] = temp;
	} */



	/* for (int i = 0; i < strlen(n) - 1; i++)			// ����
	{
		for (int j = 0; j < strlen(n) - i - 1; j++)
		{
			if (n[j] < n[j + 1])
			{
				temp = n[j];
				n[j] = n[j + 1];
				n[j + 1] = temp;
			}
		}
	} */

	//puts(n);

	//return 0;
//}