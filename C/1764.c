#include <stdio.h>  // µË∫∏¿‚
#include <stdlib.h>
#include <string.h>

int compare(void* first, void* second)
{
	return strcmp(first, second);
}

typedef struct
{
	char input[21];
}name;

typedef struct
{
	char save[21];
}ans;

name str1[1000001];
ans str2[500001];


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n + m; i++)
	{
		scanf("%s", str1[i].input);
	}

	qsort(str1, n + m, sizeof(str1[0]), compare);

	int idx = 0;
	for (int i = 0; i < n + m; i++)
	{
		if (strcmp(str1[i].input, str1[i + 1].input) == 0)
		{
			strcpy(str2[idx++].save, str1[i++].input);
		}
	}

	printf("%d\n", idx);
	for (int i = 0; i < idx; i++)
	{
		printf("%s\n", str2[i].save);
	}

	return 0;
}