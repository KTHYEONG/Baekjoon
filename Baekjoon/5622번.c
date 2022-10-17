#include <stdio.h>  // ´ÙÀÌ¾ó
#include <string.h>

int dial(int n)
{
	switch (n)
	{
	case 'A':
	case 'B':
	case 'C':
		return 3;
	case 'D':
	case 'E':
	case 'F':
		return 4;
	case 'G':
	case 'H':
	case 'I':
		return 5;
	case 'J':
	case 'K':
	case 'L':
		return 6;
	case 'M':
	case 'N':
	case 'O':
		return 7;
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
		return 8;
	case 'T':
	case 'U':
	case 'V':
		return 9;
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
		return 10;
	}
		
}

int main()
{
	char str[16];
	scanf("%s", str);

	int sum = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		for (int j = 65; j < 91; j++)
		{
			if (str[i] == j)
				sum += dial(j);
		}
	}


	printf("%d", sum);

	return 0;
}