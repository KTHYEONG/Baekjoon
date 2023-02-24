#include <stdio.h>  // 크게 만들기
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
			// push할 num이 더 크면 pop(스택의 작은 숫자 제거)
			pop(&s);
			cnt++;
			temp_idx--;
		}
		// 스택에서 현재 num(str[i])보다 작은 숫자 제거 후 push
		push(&s, str[i]);
	}
	
	// 문자를 k개보다 덜 제거 했다면 뒤의 문자부터 제거(pop)
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