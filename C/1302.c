#include <stdio.h>  // 베스트셀러
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
			// 같은 단어가 존재하면 해당 cnt 증가
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
			// 처음 나온 단어의 경우 새로 추가 
			if (flag == 0)
			{
				strcpy(b[i].name, str);
				total++;
			}
		}
	}

	// 문자열 정렬(개수가 같을 때의 경우 대비)
	qsort(b, total, sizeof(b[0]), compare);

	// 가장 많이 나온 단어 찾기
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