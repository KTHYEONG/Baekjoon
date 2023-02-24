#include <stdio.h>  // 오등큰수
#include <stdlib.h>

int cnt[1000001] = { 0, };
int input[1000001];

typedef struct
{
	int* stk;
	int ptr;
}STACK;

int is_empty(STACK* s)
{
	if (s->ptr <= -1)
		return 1;
	else
		return 0;
}

void push(STACK* s, int data)
{
	s->stk[++s->ptr] = data;
}

int pop(STACK* s)
{
	return s->stk[s->ptr--];
}

int top(STACK* s)
{
	return s->stk[s->ptr];
}


int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input[i]);
		cnt[input[i]]++;
	}

	STACK s;
	s.stk = malloc(n * sizeof(int)); s.ptr = -1;

	for (int i = 0; i < n; i++)
	{
		while (!is_empty(&s) && cnt[input[top(&s)]] < cnt[input[i]])
		{
			input[top(&s)] = input[i];
			pop(&s);
		}
		push(&s, i);
	}

	while (!is_empty(&s))
	{
		input[top(&s)] = -1;
		pop(&s);
	}

	for (int i = 0; i < n; i++)
		printf("%d ", input[i]);

	return 0;
}