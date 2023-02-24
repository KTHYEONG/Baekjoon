#include <stdio.h>  // 문자열 폭발
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char* stk;
	int size;
}STACK;

void push(STACK* s, char data)
{
	s->stk[(s->size)++] = data;
}

void pop(STACK* s)
{
	--(s->size);
}

char str[1000001];


int main()
{
	scanf("%s", str);
	int len_str = strlen(str);

	STACK s;
	s.stk = malloc(sizeof(char) * len_str);
	s.size = 0;

	char bomb[37];
	scanf("%s", bomb);
	int len_bomb = strlen(bomb);

	for (int i = 0; i < len_str; i++)
	{
		push(&s, str[i]);
		if (s.size >= len_bomb)
		{
			int temp_idx = s.size - 1;
			int flag = 0;
			for (int j = len_bomb - 1; j >= 0; j--)
			{
				if (s.stk[temp_idx] != bomb[j])
				{
					flag = 1;
					break;
				}
				temp_idx--;
			}
			if (flag == 0)
			{
				// 폭발문자 스택에서 제거하기
				for (int j = 0; j < len_bomb; j++)
				{
					pop(&s);
				}
			}
		}
	}

	if (s.size > 0)
	{
		for (int i = 0; i < s.size; i++)
		{
			printf("%c", s.stk[i]);
		}
	}
	else
		printf("FRULA");

	return 0;
}