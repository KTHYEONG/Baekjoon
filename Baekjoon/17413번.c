#include <stdio.h>  // 단어 뒤집기 2(스택)
#include <stdlib.h>
#include <string.h>

char str[100010];

typedef struct
{
	char* stk;
	int ptr;
}STACK;

int is_empty(STACK *s)
{
	if (s->ptr <= 0)
		return 1;
	else
		return 0;
}

void push(STACK* s, char c)
{
	s->stk[s->ptr++] = c;
}

void print(STACK* s)
{
	while (!is_empty(s))
	{
		printf("%c", s->stk[--s->ptr]);
	}
}

int main()
{
	fgets(str, 100010, stdin);

	STACK s;
	s.stk = (char*)malloc(strlen(str));
	s.ptr = 0;

	for (int i= 0; i < strlen(str) - 1; i++)
	{
		if (str[i] == '<')
		{
			print(&s);
			while (1)
			{
				printf("%c", str[i]);
				if (str[i] == '>')
					break;
				i++;
			}
		}
		else if (str[i] == ' ')
		{
			print(&s);
			printf(" ");
		}
		else
		{
			push(&s, str[i]);
		}
	}
	print(&s);

	free(s.stk);
	return 0;
}