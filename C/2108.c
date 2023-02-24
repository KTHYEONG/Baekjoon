/* #include <stdio.h>  // 통계학
#include <math.h>

int avg(int arr[], int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return (int)round(sum / n);
}


int median(int cnt[], int n)
{
	int num = 0;
	for (int i = 0; i < 8001; i++)
	{
		num += cnt[i];
		if (num >= (n + 1) / 2)
			return i - 4000;
	}
	return 0;
}

int mode(int cnt[], int n)
{
	int max = 0;
	int num = 0;
	int mode = 0;
	for (int i = 0; i < 8001; i++)
	{
		if (cnt[i] > max)
		{
			max = cnt[i];
			num = 1;
			mode = i - 4000;
		}
		else if (cnt[i] == max)
		{
			if (num == 1)
			{
				num++;
				mode = i - 4000;
			}
			else
				num++;
		}
	}
	return mode;
}

int min_max(int cnt[], int n)
{
	int min = 0, max = 0;
	for (int i = 8000; i >= 0; i--)
	{
		if (cnt[i] != 0)
		{
			max = i - 4000;
			break;
		}
	}

	for (int i = 0; i < 8001; i++)
	{
		if (cnt[i] != 0)
		{
			min = i - 4000;
			break;
		}

	}

	return max - min;
}


int main()
{
	int n;
	scanf("%d", &n);

	int arr[100000] = { 0, };			// 계수 정렬 이용(해당되는 숫자의 인덱스의 값을 증가시켜 개수를 파악후, 그 개수 만큼 출력 // 최댓값(기준)에 따라 효율성 달라짐)
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	int cnt[8001] = { 0, };
	for (int i = 0; i < n; i++)
	{
		cnt[arr[i] + 4000]++;
	}

	printf("%d\n", avg(arr, n));
	printf("%d\n", median(cnt, n));
	printf("%d\n", mode(cnt, n));
	printf("%d", min_max(cnt, n));

	return 0;
} */

#include <stdio.h>
#include <math.h>

int num[500000];

int avg(int arr[], int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += (double)arr[i];
	}
	return (int)round(sum / n);
}

int med(int cnt[], int n)
{
	int num = 0;
	for (int i = 0; i < 8001; i++)
	{
		num += cnt[i];
		if (num >= (n + 1) / 2)
			return i - 4000;
	}
}

int mode(int cnt[])
{
	int max = 0, check = 0, num = 0;
	for (int i = 0; i < 8001; i++)
	{
		if (cnt[i] > max)
		{
			max = cnt[i];
			check = 1;
			num = i - 4000;
		}
		else if (cnt[i] == max)
		{
			if (check == 1)
			{
				num = i - 4000;
				check++;
			}
			else
				check++;
		}
	}
	
	return num;
}

int min_max(int cnt[])
{
	int min, max;
	for (int i = 8000; i >= 0; i--)
	{
		if (cnt[i] != 0)
		{
			max = i - 4000;
			break;
		}
	}

	for (int i = 0; i <= 8000; i++)
	{
		if (cnt[i] != 0)
		{
			min = i - 4000;
			break;
		}
	}

	return max - min;
}


int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}

	int cnt[8001];
	for (int i = 0; i < 8001; i++)
		cnt[i] = 0;
	for (int i = 0; i < n; i++)
		cnt[num[i] + 4000]++;
		
	printf("%d\n", avg(num, n));
	printf("%d\n", med(cnt, n));
	printf("%d\n", mode(cnt));
	printf("%d", min_max(cnt));

	return 0;
}