#include <stdio.h>  // 단어 정렬
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int len;
	char str[51];
}list;

int compare(void* first, void* second)
{
	list* a = (list*)first;
	list* b = (list*)second;
	if (a->len > b->len)
		return 1;
	else if (a->len < b->len)
		return -1;
	else
	{
		if (strcmp(a->str, b->str) < 0)
			return -1;
		else
			return 1;
	}
}


int main()
{
	int n;
	scanf("%d", &n);

	list* arr;
	arr = (list*)malloc(n * sizeof(list));
	for (int i = 0; i < n; i++)
	{
		scanf("%s", arr[i].str);
		arr[i].len = strlen(arr[i].str);

		for (int j = 0; j < i; j++)			// 중복 단어 제거
		{
			if (strcmp(arr[i].str, arr[j].str) == 0)
			{
				i--;
				n--;
				break;
			}
		}
	}

	qsort(arr, n, sizeof(arr[0]), compare);

	for (int i = 0; i < n; i++)
	{
		printf("%s\n", arr[i].str);
	}

	return 0;
}