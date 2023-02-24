#include <stdio.h>  // 문자열 분석
#include <stdlib.h>
#include <string.h>

int main()
{
	int arr[4] = { 0, };
	char str[102];
	while (fgets(str, 110, stdin) != '\0')
	{
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				arr[0]++;
			}
			else if (str[i] >= 'A' && str[i] <= 'Z')
			{
				arr[1]++;
			}
			else if (str[i] >= '0' && str[i] <= '9')
			{
				arr[2]++;
			}
			else if (str[i] == ' ')
			{
				arr[3]++;
			}
		}

		for (int j = 0; j < 4; j++)
		{
			printf("%d ", arr[j]);
			arr[j] = 0;
		}
		printf("\n");
	}
	
	return 0;
}