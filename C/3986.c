#include <stdio.h>  // 좋은 단어
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char stk[100001];
	int size;
}STACK;

int is_empty(STACK* s)
{
	if (s->size <= 0)
		return 1;
	else
		return 0;
}

void push(STACK* s, char data)
{
	s->stk[(s->size)++] = data;
}

void pop(STACK* s)
{
	--(s->size);
}

char top(STACK* s)
{
	int temp = s->size;
	return s->stk[--temp];
}

char str[100001];

int main()
{
	int n;
	scanf("%d", &n);

	STACK s;
	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		int len = strlen(str);
		s.size = 0;

		for (int j = 0; j < len; j++)
		{
			if (is_empty(&s))
			{
				push(&s, str[j]);
			}
			else
			{
				if (str[j] == top(&s))
				{
					pop(&s);
				}
				else
				{
					push(&s, str[j]);
				}
			}
		}
		if (is_empty(&s))
			ans++;
	}
	printf("%d", ans);

	return 0;
}