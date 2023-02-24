#include <stdio.h>  // ũ�� �����
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char* stk;
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

char top(STACK* s)
{
	int temp = s->size;
	return s->stk[--temp];
}

void pop(STACK* s)
{
	--(s->size);
}

char str[500001];


int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	scanf("%s", str);
	int len = strlen(str);

	STACK s;
	s.size = 0;
	s.stk = (char*)malloc(sizeof(char) * len);

	int cnt = 0;
	for (int i = 0; i < len; i++)
	{
		int temp_idx = s.size;
		while ((!is_empty(&s)) && (cnt < k) && (str[i] > top(&s)))
		{
			// push�� num�� �� ũ�� pop(������ ���� ���� ����)
			pop(&s);
			cnt++;
			temp_idx--;
		}
		// ���ÿ��� ���� num(str[i])���� ���� ���� ���� �� push
		push(&s, str[i]);
	}
	
	// ���ڸ� k������ �� ���� �ߴٸ� ���� ���ں��� ����(pop)
	if (cnt < k)
	{
		int temp = k - cnt;
		while (temp > 0)
		{
			pop(&s);
			temp--;
		}
	}

	for (int i = 0; i < s.size; i++)
	{
		printf("%c", s.stk[i]);
	}

	return 0;
}