#include <stdio.h>  // 문자열 집합
#include <string.h>

typedef struct
{
	char str[501];
}string;

string s[10000];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", s[i].str);
	}

	int ans = 0;
	char check_str[501];
	for (int i = 0; i < m; i++)
	{
		scanf("%s", check_str);
		for (int j = 0; j < n; j++)
		{
			if (strcmp(s[j].str, check_str) == 0)
			{
				ans++;
				break;
			}
		}
	}
	printf("%d", ans);

	return 0;
}

/*
#include <stdio.h>  // 문자열 집합
#include <string.h>

char str[10000][501];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", str[i]);
	}

	int ans = 0;
	char check_str[501];
	for (int i = 0; i < m; i++)
	{
		scanf("%s", check_str);
		for (int j = 0; j < n; j++)
		{
			if (strcmp(str[j], check_str) == 0)
			{
				ans++;
				break;
			}
		}
	}
	printf("%d", ans);

	return 0;
}
*/