#include <stdio.h>  // Á¦·Î
#include <stdlib.h>

typedef struct
{
	int* stk;
	int ptr;
}STACK;

int is_empty(STACK* s)
{
	if (s->ptr <= 0)
		return 1;
	else
		return 0;
}

void push(STACK* s, int num, int k, int *sum)
{
	if (s->ptr <= k)
	{
		s->stk[s->ptr++] = num;
		*sum += num;
	}
}

void pop(STACK* s, int *sum)
{
	if (!is_empty(s))
	{
		*sum -= s->stk[--s->ptr];
	}
}


int main()
{
	int k;
	scanf("%d", &k);

	STACK s;
	s.stk = malloc(k * sizeof(int));
	s.ptr = 0;

	int num, sum = 0;
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &num);
		if (num)
			push(&s, num, k, &sum);
		else
			pop(&s, &sum);
	}

	printf("%d", sum);

	return 0;
}