#include <stdio.h>  // 그룹 단어 체커
#include <string.h>

int main()
{
	int N;
	scanf("%d", &N);

	int count = 0; char str[101];
	for (int i = 0; i < N; i++)
	{
		scanf("%s", str);

		int length = strlen(str);
		if (length <= 2)                                // 문자 길이 2이하는 무조건 정답
			count++;
		else
		{
			int check = 0;
			for (int j = 0; j < length - 2; j++)
			{
				for (int k = j + 2; k < length; k++)    // 2번째 뒤에 있는 문자부터 끝까지 일치하는게 있는지 찾기 
				{
					if (str[j] == str[k] && str[j] != str[k - 1])
					{
						check = 1;
						break;
					}
				}
			}
			if (check == 0)
				count++;
		}
	}

	printf("%d", count);

	return 0;
}