#include <stdio.h>  // 직사각형에서의 탈출

#define min(a, b) a > b ? b : a

int main()
{
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);

	int a = min(w - x, h - y);
	int b = min(x, y);
	int result = min(a, b);

	printf("%d", result);

	return 0;
}