#include <stdio.h>  // ¼è¸·´ë±â
#include <stdlib.h>
#include <string.h>

char str[100001];

typedef struct
{
	char* stk;
	int ptr;
}STACK;

int is_empty(STACK* s)
{
	if (s->ptr <= 0)
		return 1;
	else
		return 0;
}

void push(STACK* s, char data)
{
	s->stk[s->ptr++] = data;
}

void pop(STACK* s)
{
	if (!is_empty(s))
	{
		s->ptr--;
	}
}


int main()
{
	scanf("%s", str);

	STACK s;
	int count = 0;
	s.stk = malloc(strlen(str) * sizeof(char) - 1);
	s.ptr = 0;

	push(&s, str[0]);
	for (int i = 1; i < strlen(str); i++)
	{
		if (str[i] == '(')
		{
			push(&s, str[i]);
		}
		else if (str[i] == ')')
		{
			if (str[i - 1] == '(')
			{
				pop(&s);
				count += s.ptr;
			}
			else if (str[i - 1] == ')')
			{
				pop(&s);
				count++;
			}
		}
	}

	printf("%d", count);

	return 0;
}