#include <stdio.h>  // 단어 뒤집기
#include <string.h>

int main()
{
	int t;
	scanf("%d ", &t);

	char str[1001], stack[1001];
	int top = 0;
	for (int i = 0; i < t; i++)
	{
		fgets(str, 1001, stdin);
		for (int j = 0; j < strlen(str) - 1; j++)
		{
			if (str[j] != ' ')
			{
				stack[top++] = str[j];
			}
			if (str[j] == ' ' || j == strlen(str) - 2)
			{
				for (int k = top - 1; k >= 0; k--)
				{
					printf("%c", stack[k]);
				}
				printf(" ");
				top = 0;
			}
		}
		printf("\n");
	}


	return 0;
}

/*
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
	if (!is_empty(s))
		return s->stk[--s->ptr];
}

char str[200010];


int main()
{
	int t;
	scanf("%d ", &t);

	STACK s;
	for (int i = 0; i < t; i++)
	{
		fgets(str, 200010, stdin);
		int len = strlen(str);
		s.ptr = 0; s.stk = (char*)malloc(sizeof(char) * len - 1);

		for (int j = 0; j < len - 1; j++)
		{
			if (str[j] != ' ')
				push(&s, str[j]);

			if (str[j] == ' ' || j == len - 2)
			{
				while (!is_empty(&s))
				{
					printf("%c", pop(&s));
				}
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}
*/