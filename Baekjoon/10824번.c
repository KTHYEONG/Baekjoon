#include <stdio.h>  // 네 수(새로운 함수 복습)
#include <stdlib.h>
#include <string.h>
#define MAX 1000000

char a_str[MAX + 1];
char b_str[MAX + 1];
char c_str[MAX + 1];
char d_str[MAX + 1];

int main()
{
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);

	sprintf(a_str, "%d", a);			// 정수를 문자열로 바꾼 뒤 변수에 저장(by sprintf)
	sprintf(b_str, "%d", b);
	sprintf(c_str, "%d", c);
	sprintf(d_str, "%d", d);

	strcat(a_str, b_str);			// 문자열 합치기
	strcat(c_str, d_str);

	long long int a_b, c_d;			// 문자열을 정수로 바꾼 뒤 변수에 저장(by strtol)
	a_b = strtol(a_str, NULL, 10);
	c_d = strtol(c_str, NULL, 10);

	printf("%lld", a_b + c_d);

	return 0;
}