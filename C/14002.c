#include <stdio.h>  // 가장 긴 증가하는 부분 수열 4   // 코드 다시 이해
#include <stdlib.h>

typedef struct
{
	int *stk;
	int ptr;
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
	s->stk[s->ptr++] = data;
}

int pop(STACK* s)
{
	return s->stk[--s->ptr];
}

int top(STACK* s)
{
	int temp = s->ptr;
	return s->stk[--temp];
}


int main()
{
	int n;
	scanf("%d", &n);

	int arr[1001];
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	int dp[1001][2];
	for (int i = 1; i <= n; i++)
		dp[i][0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j] && dp[i][0] < dp[j][0] + 1)
			{
				dp[i][0] = dp[j][0] + 1;
				dp[i][1] = arr[j];
			}
		}
	}

	int max = 0, idx = 0;
	for (int i = 1; i <= n; i++)
	{
		if (max < dp[i][0])
		{
			max = dp[i][0];
			idx = i;
		}
	}

	STACK s;
	s.ptr = 0; s.stk = malloc(sizeof(int) * n);
	push(&s, arr[idx]);
	for (int i = n; i > 0; i--)
	{
		if (arr[i] == top(&s))
			push(&s, dp[i][1]);
	}

	printf("%d\n", max);			// 길이

	s.ptr--;
	while (!is_empty(&s))			// 부분 수열
		printf("%d ", pop(&s));

	return 0;
}