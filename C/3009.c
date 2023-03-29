#include <stdio.h>  // 네 번째 점


int main()
{
	int x[3], y[3];
	for (int i = 0; i < 3; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
	}

	int ans_x, ans_y;
	if (x[0] == x[1])
		ans_x = x[2];
	else
	{
		if (x[0] == x[2])
			ans_x = x[1];
		else
			ans_x = x[0];
	}

	if (y[0] == y[1])
		ans_y = y[2];
	else
	{
		if (y[0] == y[2])
			ans_y = y[1];
		else
			ans_y = y[0];
	}
	printf("%d %d", ans_x, ans_y);
		

	return 0;
}