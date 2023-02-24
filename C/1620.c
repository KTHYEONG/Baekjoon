#include <stdio.h>  // 나는야 포켓몬 마스터 이다솜
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char name[21];
	int num;
}node;

int compare(void* first, void* second)
{
	node* a = (node*)first;
	node* b = (node*)second;
	if (strcmp(a->name, b->name) > 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

void binary_search(node* sorted, char* str, int n)
{
	int left, right, mid;

	left = 0, right = n - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (strcmp(sorted[mid].name, str) == 0)
		{
			printf("%d\n", sorted[mid].num);
			break;
		}
		else if (strcmp(sorted[mid].name, str) > 0)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
}


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	node* list = (node*)malloc(sizeof(node) * n);
	node* sorted = (node*)malloc(sizeof(node) * n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", list[i].name);
		list[i].num = sorted[i].num = i + 1;
		sorted[i] = list[i];
	}

	qsort(sorted, n, sizeof(sorted[0]), compare);

	char str[21];
	for (int i = 0; i < m; i++)
	{
		scanf("%s", str);
		if (str[0] >= '0' && str[0] <= '9')
		{
			int idx = atoi(str);
			printf("%s\n", list[idx - 1].name);
		}
		else
		{
			binary_search(sorted, str, n);
		}
	}

	free(list);
	free(sorted);

	return 0;
}