#include <stdio.h>  // 사탕 게임
#include <stdlib.h>

#define max(a, b) a > b ? a : b

void swap(char *a, char *b)
{
	char c;
	c = *a;
	*a = *b;
	*b = c;
}

int check(char** arr, int n)
{
	int temp = 0, count = 1;			

	for (int i = 0; i < n; i++)			// 가로로 확인
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (arr[i][j] == arr[i][j + 1])
				count++;
			else
			{
				temp = max(temp, count);
				count = 1;
			}
				
		}
		temp = max(temp, count);
		count = 1;
	}

	for (int i = 0; i < n; i++)			// 세로로 확인
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (arr[j][i] == arr[j + 1][i])
				count++;
			else
			{
				temp = max(temp, count);
				count = 1;
			}
		}
		temp = max(temp, count);
		count = 1;
	}

	return temp;
}


int main()
{
	int n;
	scanf("%d", &n);

	char** arr;
	arr = (char**)malloc(sizeof(char*) * n);

	for (int i = 0; i < n; i++)
	{
		*(arr + i) = (char*)malloc(sizeof(char) * n);
		scanf("%s", arr[i]);
	}

	int answer = 0;
	for (int i = 0; i < n; i++)			// 가로로 교환
	{
		for (int j = 0; j < n - 1; j++)
		{
			swap(&arr[i][j], &arr[i][j + 1]);
			answer = max(answer, check(arr, n));
			swap(&arr[i][j], &arr[i][j + 1]);
		}
	}

	for (int i = 0; i < n; i++)			// 세로로 교환
	{
		for (int j = 0; j < n - 1; j++)
		{
			swap(&arr[j][i], &arr[j + 1][i]);
			answer = max(answer, check(arr, n));
			swap(&arr[j][i], &arr[j + 1][i]);
		}
	}

	printf("%d", answer);

	return 0;
}