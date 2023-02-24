#include <stdio.h>  // 후위 표기식2
#include <stdlib.h>
#include <string.h>

typedef struct
{
	double *stk;
	int ptr;
}STACK;

void push(STACK* s, double data)
{
	s->stk[s->ptr++] = data;
}

double pop(STACK* s)
{
	return s->stk[--s->ptr];
}

double calculate(char c, double first, double second)
{
	switch (c)
	{
	case '*':
		return first * second;
	case '/':
		return second / first;
	case '+':
		return first + second;
	case '-':
		return second - first;
	}
}


int main()
{
	int n;
	scanf("%d", &n);

	char str[101];
	scanf("%s", str);

	int arr[26];
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	STACK s;
	s.ptr = 0; s.stk = malloc(sizeof(double) * n);

	double first, second;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')			// 문자
		{
			push(&s, arr[str[i] - 'A']);
		}
		else			// 연산자
		{
			first = pop(&s);
			second = pop(&s);
			push(&s, calculate(str[i], first, second));
		}
	}

	double result = pop(&s);
	printf("%.2f\n", result);
	
	return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	double* stk;
	int ptr;
}STACK;

int is_empty(STACK* s)
{
	if (s->ptr <= 0)
		return 1;
	else
		return 0;
}

void push(STACK* s, double data)
{
	s->stk[s->ptr++] = data;
}

double pop(STACK* s)
{
	if (!is_empty(s))
		return s->stk[--s->ptr];
}


int main()
{
	int n;
	scanf("%d", &n);

	char str[101];
	scanf("%s", str);

	double arr[26] = { 0, };
	for (int i = 0; i < n; i++)
		scanf("%lf", &arr[i]);

	STACK s;
	s.ptr = 0; s.stk = (double*)malloc(sizeof(double) * n);

	int len = strlen(str);
	double result = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			push(&s, arr[str[i] - 'A']);
		}
		else if (str[i] == '*')
		{
			double num1 = pop(&s);
			double num2 = pop(&s);
			result = num1 * num2;
			push(&s, result);
		}
		else if (str[i] == '/')
		{
			double num1 = pop(&s);
			double num2 = pop(&s);
			result = num2 / num1;
			push(&s, result);
		}
		else if (str[i] == '+')
		{
			double num1 = pop(&s);
			double num2 = pop(&s);
			result = num1 + num2;
			push(&s, result);
		}
		else if (str[i] == '-')
		{
			double num1 = pop(&s);
			double num2 = pop(&s);
			result = num2 - num1;
			push(&s, result);
		}
	}

	printf("%.2f", pop(&s));

	return 0;
}
*/