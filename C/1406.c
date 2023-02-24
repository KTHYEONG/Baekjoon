#include <stdio.h>  // ¿¡µğÅÍ
#include <stdlib.h>
#include <string.h>

char l_stk[600010], r_stk[300010];
int left, right = 300000;

int main()
{
	scanf("%s", l_stk);

	left = strlen(l_stk);

	int m;
	scanf("%d", &m);

	char input;
	for (int i = 0; i < m; i++)
	{
		scanf("\n%c", &input);
		if (input == 'P')
		{
			char c;
			scanf(" %c", &c);
			l_stk[left++] = c;
		}
		else if (input == 'L' && left != 0)
		{
			r_stk[right--] = l_stk[--left];
			l_stk[left] = '\0';

		}
		else if (input == 'B' && left != 0)
		{
			l_stk[--left] = '\0';
		}
		else if (input == 'D' && right != 300000)
		{
			l_stk[left++] = r_stk[++right];
			r_stk[right] = '\0';
		}
	}

	printf("%s%s", l_stk, &r_stk[right + 1]);

	return 0;
}