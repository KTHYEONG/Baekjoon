#include <stdio.h>  // ü���� �ٽ� ĥ�ϱ�

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);

	char board[50][50];			// �Է� ���� ���� ����
	for (int i = 0; i < m; i++)
	{
		scanf("%s", &board[i]);
	}

	char chess_B[8][8];			// �������, �������� �� ����� 8*8 ������ ü���� ����
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
	for (int i = 0; i < m - 7; i++)			// 8*8 ������� �Է¹��� �簢�� �߶󳻱�
	{
		for (int j = 0; j < n - 7; j++)
		{
			int min_B = 0, min_W = 0;
			for (int k1 = 0; k1 < 8; k1++)			// ü������� �Է¹��� ���� ���ϱ�
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