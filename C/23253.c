#include <stdio.h>  // 자료구조는 정말 최고야
#include <stdlib.h>

int arr[200000] = { 0, };

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int max;
    for (int i = 0; i < m; i++)
    {
        int k;
        scanf("%d ", &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &arr[i]);
        }

        max = arr[0];
        for (int j = 1; j < k; j++)
        {
            if (arr[i] > max)
            {
                printf("No");
                return 0;
            }
        }
    }

    printf("Yes");

    return 0;
}