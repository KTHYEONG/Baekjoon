#include <stdio.h>  // 체스판 다시 칠하기

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);

	char board[50][50];			// 입력 받은 보드 저장
	for (int i = 0; i < m; i++)
	{
		scanf("%s", &board[i]);
	}

	char chess_B[8][8];			// 흰색시작, 검정시작 두 경우의 8*8 사이즈 체스판 저장
	char chess_W[8][8];
	int flag = 1;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (flag == 1)
			{
				chess_B[i][j] = 'B';
				chess_W[i][j] = 'W';
			}
			else
			{
				chess_B[i][j] = 'W';
				chess_W[i][j] = 'B';
			}
			flag *= -1;
		}
		flag *= -1;
	}

	int min = m * n;
	for (int i = 0; i < m - 7; i++)			// 8*8 사이즈로 입력받은 사각형 잘라내기
	{
		for (int j = 0; j < n - 7; j++)
		{
			int min_B = 0, min_W = 0;
			for (int k1 = 0; k1 < 8; k1++)			// 체스보드와 입력받은 보드 비교하기
			{
				for (int k2 = 0; k2 < 8; k2++)
				{
					if (chess_B[k1][k2] != board[i + k1][j + k2])
						min_B++;
					if (chess_W[k1][k2] != board[i + k1][j + k2])
						min_W++;
				}
			}
			if (min > min_B)
				min = min_B;
			if (min > min_W)
				min = min_W;
		}
	}

	printf("%d", min);

	return 0;
}