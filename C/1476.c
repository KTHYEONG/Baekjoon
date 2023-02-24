#include <stdio.h>  // 날짜 계산


int main()
{
	int e, s, m;
	scanf("%d %d %d", &e, &s, &m);

	int answer = 0;
	int i = 1, j = 1, k = 1;
	while (1)
	{
		answer++;
		if (i == e && j == s && k == m)
		{
			printf("%d", answer);
			break;
		}

		i++; j++; k++;

		if (i == 16)
			i = 1;
		if (j == 29)
			j = 1;
		if (k == 20)
			k = 1;

	}

	return 0;
}