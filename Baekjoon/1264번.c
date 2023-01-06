#include <stdio.h>  // 모음의 개수
#include <string.h>

int main()
{
	char str[257];
	int answer = 0;
	while (1)
	{
		fgets(str, 257, stdin);
		if (str[0] == '#')
			break;

		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == 'a' || str[i] == 'A')
				answer++;
			else if (str[i] == 'e' || str[i] == 'E')
				answer++;
			else if (str[i] == 'i' || str[i] == 'I')
				answer++;
			else if (str[i] == 'o' || str[i] == 'O')
				answer++;
			else if (str[i] == 'u' || str[i] == 'U')
				answer++;
		}
		printf("%d\n", answer);
		answer = 0;
	}

	return 0;
}