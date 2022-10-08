#include <stdio.h> // 알람 시계

int main()
{
	int h, m;

	scanf("%d %d", &h, &m);
	m -= 45;

	if (m >= 0)
		printf("%d %d", h, m);
	else
	{
		m += 60;
		h--;
		if (h < 0)
		{
			h = 23;
		}
		printf("%d %d", h, m);
	}

	return 0;
}