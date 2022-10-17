#include <stdio.h>  // ¼¿ÇÁ ³Ñ¹ö

int SELF(int n)
{
	int sum = n;
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	
	return sum;
}

int main()
{
	int arr[10001] = { 0, }, result;

	for (int i = 0; i < 10001; i++)
	{
		result = SELF(i);
		if (result < 10001)
			arr[result] = 1;
	}
	
	for (int j = 0; j < 10001; j++)
	{
		if (arr[j] != 1)
			printf("%d\n", j);
	}


	return 0;
}