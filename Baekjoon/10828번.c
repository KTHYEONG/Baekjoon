#include <stdio.h>  // Ω∫≈√
#include <string.h>

int stack[10000];
int count = 0;

void push(int num)
{
	stack[count] = num;
	count++;
}

void pop()
{
	if (count != 0)
	{
		count--;
		printf("%d\n", stack[count]);
	}
	else
		printf("%d\n", -1);
}

void size()
{
	printf("%d\n", count);
}

void empty()
{
	if (count != 0)
		printf("%d\n", 0);
	else
		printf("%d\n", 1);
}

void top()
{
	if (count != 0)
		printf("%d\n", stack[count - 1]);
	else
		printf("%d\n", -1);
}


int main()
{
	int n;
	scanf("%d", &n);

	char str[10];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		if (strcmp(str, "push") == 0)
		{
			int num;
			scanf("%d", &num);
			push(num);
		}
		else if (strcmp(str, "pop") == 0)
			pop();
		else if (strcmp(str, "size") == 0)
			size();
		else if (strcmp(str, "empty") == 0)
			empty();
		else if (strcmp(str, "top") == 0)
			top();
	}

	return 0;
}