#include <stdio.h>  // ����Ʈ����
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char name[51];
	int cnt;
}book;

int compare(void* a, void* b)
{
	if (strcmp(a, b) > 0)
		return 1;
	else
		return -1;
}

int main()
{
	int n;
	scanf("%d", &n);

	book b[1000];

	char str[51];
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);

		b[i].cnt = 0;
		if (i == 0)
		{
			strcpy(b[i].name, str);
			total++;
		}
		else
		{
			// ���� �ܾ �����ϸ� �ش� cnt ����
			int j = 0, flag = 0;
			while (j < i)
			{
				if (strcmp(str, b[j].name) == 0)
				{
					flag = 1;
					b[j].cnt++;
					break;
				}
				j++;
			}
			// ó�� ���� �ܾ��� ��� ���� �߰� 
			if (flag == 0)
			{
				strcpy(b[i].name, str);
				total++;
			}
		}
	}

	// ���ڿ� ����(������ ���� ���� ��� ���)
	qsort(b, total, sizeof(b[0]), compare);

	// ���� ���� ���� �ܾ� ã��
	int idx, ans = 0, max = -1;
	for (idx = 0; idx < total; idx++)
	{
		if (b[idx].cnt > max)
		{
			max = b[idx].cnt;
			ans = idx;
		}
	}

	printf("%s", b[ans].name);

	return 0;
}