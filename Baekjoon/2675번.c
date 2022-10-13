#include <stdio.h>  // 문자열 반복
#include <string.h>

int main()
{
	int T, R;
	char S[20];
	scanf("%d", &T);
	
	for (int i = 0; i < T; i++)
	{
		scanf("%d %s", &R, S);
		int length = strlen(S);
		for (int j = 0; j < length; j++)
		{
			for (int k = 0; k < R; k++)
			{
				printf("%c", S[j]);
			}
		}
		printf("\n");
	}

	return 0;
}


/*for (int i = 0; i < length - 1; i++)                   //버블정렬//
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}*/


	/* int j;                                           //삽입정렬//
		for (int i = 1; i < length; i++)
		{
			temp = arr[i];
			for (j = i - 1; j >= 0 && arr[j] > temp; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		} */