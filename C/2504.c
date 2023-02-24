#include <stdio.h>  // 괄호의 값
#include <stdlib.h>
#include <string.h>

// 스택에 문자를 저장하는 것이아닌 숫자로 저장
#define round -1
#define angled -2

typedef struct
{
	int ptr;
	int*stk;
}STACK;

int is_empty(STACK* s)
{
	if (s->ptr <= 0)
		return 1;
	else
		return 0;
}

void push(STACK* s, int data)
{
	s->stk[(s->ptr)++] = data;
}

int pop(STACK* s)
{
	if (is_empty(s))
	{
		return 0;
	}
	else
	{
		return s->stk[--(s->ptr)];
	}
}

int top(STACK* s)
{
	int temp = s->ptr;
	return s->stk[--temp];
}

int corret(STACK* s, char* str, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '(')
		{
			push(s, round);
		}
		else if (str[i] == '[')
		{
			push(s, angled);
		}
		else if (!is_empty(s))
		{
			int temp = top(s);
			if (str[i] == ')' && temp == round)
			{
				pop(s);
			}
			else if (str[i] == ']' && temp == angled)
			{
				pop(s);
			}
			else
				return 0;
		}
		else
		{
			return 0;
		}
	}
	if (is_empty(s))
		return 1;
	else
		return 0;
}

int calculate(STACK* s, char* str, int len)
{
	int sum, temp;
	for (int i = 0; i < len; i++)
	{
		sum = 0;
		if (str[i] == '(')
		{
			push(s, round);
		}
		else if (str[i] == '[')
		{
			push(s, angled);
		}
		else if (str[i] == ')')
		{
			while ((temp = pop(s)) != round)
			{
				sum += temp;
			}
			if (sum == 0)
			{
				push(s, 2);
			}
			else
			{
				push(s, sum * 2);
			}
		}
		else if (str[i] == ']')
		{
			while ((temp = pop(s)) != angled)
			{
				sum += temp;
			}
			if (sum == 0)
			{
				push(s, 3);
			}
			else
			{
				push(s, sum * 3);
			}
		}
	}
	sum = 0;
	while (!is_empty(s))
	{
		sum += pop(s);
	}
	return sum;
}


int main()
{
	char str[31];
	scanf("%s", str);
	int len = strlen(str);

	STACK s;
	s.ptr = 0;
	s.stk = malloc(sizeof(int) * len);
	
	if (corret(&s, str, len) == 0)
	{
		printf("%d", 0);
	}
	else
	{
		printf("%d", calculate(&s, str, len));
	}

	
	return 0;
}