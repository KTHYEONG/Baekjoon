#include <stdio.h>  // 괄호
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char *stk;
	int ptr;
}Stack;

void push(Stack* s)
{
	if (s->ptr >= 50)
		return;
	s->stk[++s->ptr] = '(';
}

char pop(Stack* s)
{
	if (s->ptr < 0)
		return '`';
	else
	{
		char num = s->stk[s->ptr--];
		return num;
	}
}

int main()
{
	int t;
	scanf("%d ", &t);

	Stack s;
	s.stk = (char*)malloc(t * sizeof(char));
	for (int i = 0; i < t; i++)
	{
		int check = 1;
		s.ptr = -1;			// 배열의 인덱스 0으로 시작
		fgets(s.stk, 52, stdin);
		for (int j = 0; j < strlen(s.stk) - 1; j++)
		{
			if (s.stk[j] == '(')
				push(&s);
			else if (s.stk[j] == ')')
			{
				char num;
				num = pop(&s);
				if (num != '(')
				{
					check = 0;
					break;
				}
			}
		}
		if (check == 0 || s.ptr != -1)
			printf("NO\n");
		else
			printf("YES\n");
	}

	return 0;
}