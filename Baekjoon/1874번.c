#include <stdio.h>  // 스택 수열
#include <stdlib.h>

char result[200000];

typedef struct 
{
	int* stk;
	int ptr;
}STACK;

int main()
{
	int n;
	scanf("%d", &n);

	STACK s;
	int* arr = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	s.stk = malloc(100000 * sizeof(int));
	s.ptr = -1;
	int num = 1, idx = 0, result_idx = 0;
	while (1)
	{
		if (s.ptr == -1 || s.stk[s.ptr] < arr[idx])			// push
		{
			s.stk[++s.ptr] = num++;
			result[result_idx++] = '+';
		}
		else if (s.stk[s.ptr] == arr[idx])			// pop
		{
			s.ptr--;
			result[result_idx++] = '-';
			idx++;
		}
		else
		{
			printf("NO\n");
			return 0;
		}		
		if (result_idx == 2 * n)
			break;
	}

	for (int i = 0; i < result_idx; i++)
	{
		printf("%c\n", result[i]);
	}

	free(arr);
	return 0;
}