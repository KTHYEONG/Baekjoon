#include <stdio.h>  // 큰 수 A + B
#include <string.h>

void reverse(char arr[])
{
	int len = strlen(arr);
	char temp;
	for (int i = 0; i < len / 2; i++)
	{
		temp = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = temp;
	}
}


int main()			// c언어 큰 수 계산 --> 숫자를 문자열로 받은후 거꾸로 뒤집은 형태를 계산
{
	char a[10002] = { 0, }, b[10002] = { 0, }, rev[10003] = { 0, };
	scanf("%s %s", a, b);

	reverse(a);
	reverse(b);

	int a_len = strlen(a), b_len = strlen(b);
	int max_len = a_len > b_len ? a_len : b_len;

	int sum = 0, flag = 0;
	for (int i = 0; i < max_len; i++)
	{
		sum = a[i] - '0' + b[i] - '0' + flag;
		if (sum < 0)			// a와 b 두 수의 자리수가 다른 경우
			sum += '0';

		if (sum > 9)			// 합이 9 넘으면 다음 자리수 +1
			flag = 1;
		else
			flag = 0;
		rev[i] = sum % 10 + '0';			// 정수 -- > 문자 형태로 저장
	}
	if (flag == 1)			// 마지막 공간(뒤집으면 맨 처음)에 1 추가
		rev[max_len] = '1';


	reverse(rev);			// 뒤집은 배열을 원상태로 복구
	printf("%s", rev);

	return 0;
}