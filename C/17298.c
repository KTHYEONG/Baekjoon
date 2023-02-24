#include <stdio.h>  // ¿ÀÅ«¼ö
#include <stdlib.h>

int arr[1000000];

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

int top(STACK* s)
{
	int temp = s->ptr;
	return s->stk[--temp];
}

void push(STACK* s, int data)
{
	s->stk[s->ptr++] = data;
}

void pop(STACK* s)
{
	--s->ptr;
}


int main()
{
	int n;
	scanf("%d", &n);

	STACK s;
	s.stk = malloc(n * sizeof(int));
	s.ptr = 0;

	int num;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		arr[i] = num;
		while (1)
		{
			if (is_empty(&s))
			{
				push(&s, i);
				break;
			}

			int idx = top(&s);
			if (num > arr[idx])
			{
				arr[idx] = num;
				pop(&s);
			}
			else
			{
				push(&s, i);
				break;
			}
		}
	}

	while (!is_empty(&s))
	{
		int idx = top(&s);
		arr[idx] = -1;
		pop(&s);
	}

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;
}