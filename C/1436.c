#include <stdio.h>  // ��ȭ���� ��

int main()
{
    int n;
    scanf("%d", &n);

    int count = 0;
    int num = 666;
    while (1)
    {
        int check = 0;
        int temp = num;
        while (temp > 0)            // 6�� �������� 3�� �������� üũ
        {
            int digit = temp % 10;
            if (digit == 6)
                check++;
            else
                check = 0;
            if (check == 3)
            {
                count++;
                break;
            }
            temp /= 10;
        }
        if (count == n)
            break;
        num++;
    }

    printf("%d", num);

    return 0;
}