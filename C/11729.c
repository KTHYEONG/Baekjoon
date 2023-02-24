/* #include <stdio.h>  // 하노이 탑 이동 순서
#include <math.h>

void hanoi(int n, int from, int temp, int to)
{
	if (n == 1)
		printf("1번 %d %d\n", from, to);
	else
	{
		hanoi(n - 1, from, to, temp);
		printf("%d번 %d %d\n", n, from, to);
		//hanoi(1, from, temp, to);
		hanoi(n - 1, temp, from, to);
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	int count = pow(2, n) - 1;
	printf("%d\n", count);
	hanoi(n, 1, 2, 3);

	return 0;
} */

#include <stdio.h>
#include <math.h>

void hanoi(int n, int from, int temp, int to)
{
	if (n == 1)
		printf("%d %d\n", from, to);
	else
	{
		hanoi(n - 1, from, to, temp);
		hanoi(1, from, temp, to);
		hanoi(n - 1, temp, from, to);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	
	int cnt;
	cnt = pow(2, n) - 1;
	printf("%d\n", cnt);
	hanoi(n, 1, 2, 3);

	return 0;
}