#include <stdio.h>  // ���

void PRINT(int arr[])
{
	for (int i = 0; i < 3; i++)
	{
		printf("%d", arr[i]);
	}
}


int main()
{
	int A, B;
	scanf("%d %d", &A, &B);
	
	int arr1[3], arr2[3];                    // �� �迭�� �ڸ��� �ݴ�� ����
	arr1[0] = A % 10;
	arr1[1] = (A / 10) % 10;
	arr1[2] = A / 100;

	arr2[0] = B % 10;
	arr2[1] = (B / 10) % 10;
	arr2[2] = B / 100;

	if (arr1[0] > arr2[0])                  // �ڸ��� ���� ũ�� �� �� ���
		PRINT(arr1);
	else if (arr1[0] < arr2[0])
		PRINT(arr2);
	else
	{
		if (arr1[1] > arr2[1])
			PRINT(arr1);
		else if(arr1[1] < arr2[1])
			PRINT(arr2);
		else
		{
			if (arr1[2] > arr2[2])
				PRINT(arr1);
			else if (arr1[2] < arr2[2])
				PRINT(arr2);
		}
	}

	return 0;
}