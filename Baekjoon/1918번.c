/*#include <stdio.h>  // 후위 표기식
#include <stdlib.h>
#include <string.h>

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

char pop(STACK* s)
{
	return s->stk[--s->ptr];
}

char top(STACK* s)
{
	int temp = s->ptr;
	return s->stk[--temp];
}


int main()
{
	char str[101];
	scanf("%s", str);

	STACK s;
	s.ptr = 0; s.stk = malloc(sizeof(char) * strlen(str));

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			printf("%c", str[i]);
		}
		else
		{
			if (str[i] == '(')
			{
				push(&s, str[i]);
			}
			else if (str[i] == '*' || str[i] == '/')
			{
				while (!is_empty(&s) && ((top(&s) == '*' || top(&s) == '/')))
				{
					printf("%c", pop(&s));
				}
				push(&s, str[i]);
			}
			else if (str[i] == '+' || str[i] == '-')
			{
				while (!is_empty(&s) && top(&s) != '(')
				{
					printf("%c", pop(&s));
				}
				push(&s, str[i]);
			}
			else if (str[i] == ')')
			{
				while (!is_empty(&s) && top(&s) != '(')
				{
					printf("%c", pop(&s));
				}
				pop(&s);
			}
		}
	}

	while (!is_empty(&s))
	{
		printf("%c", pop(&s));
	}

	return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char pop(STACK* s)
{
	return s->stk[--s->ptr];
}

char top(STACK* s)
{
	int temp = s->ptr;
	return s->stk[--temp];
}


int main()
{
	char str[101];
	scanf("%s", str);

	STACK s;
	s.ptr = 0; s.stk = (char*)malloc(sizeof(char) * strlen(str));

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			printf("%c", str[i]);
		}
		else if (str[i] == '(')
		{
			push(&s, str[i]);
		}
		else if (str[i] == '*' || str[i] == '/')
		{
			while (!is_empty(&s) && (top(&s) == '*' || top(&s) == '/'))
			{
				printf("%c", pop(&s));
			}
			push(&s, str[i]);
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			while (!is_empty(&s) && top(&s) != '(')
			{
				printf("%c", pop(&s));
			}
			push(&s, str[i]);
		}
		else if (str[i] == ')')
		{
			while (!is_empty(&s) && top(&s) != '(')
			{
				printf("%c", pop(&s));
			}
			pop(&s);
		}
	}

	while (!is_empty(&s))
		printf("%c", pop(&s));

	return 0;
}