void bubble(int* arr, int n)
{
	int temp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void insertion(int* arr, int n)
{
	int key, j;
	for (int i = 1; i < n; i++)
	{
		key = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > key; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}

int compare(void* first, void* second)
{
	int* a = first;
	int* b = second;
	if (*a > *b)
		return 1;
	else if (*a < *b)
		return -1;
	else
		return 0;
}

int sort[500000];
void merge(int* arr, int start, int mid, int end)
{
	int i, j, k;
	i = start;
	j = mid + 1;
	k = start;

	while (i <= mid && j <= end)
	{
		if (arr[i] >= arr[j])
			sort[k++] = arr[j++];
		else
			sort[k++] = arr[i++];
	}

	if (i > mid)
	{
		for (int idx = j; idx <= end; idx++)
			sort[k++] = arr[idx];
	}
	else
	{
		for (int idx = i; idx <= mid; idx++)
			sort[k++] = arr[idx];
	}
	
	for (int idx = start; idx <= end; idx++)
		arr[idx] = sort[idx];
}

void merge_sort(int* arr, int start, int end)
{
	int mid;
	if (start < end)
	{
		mid = (start + end) / 2;
		merge_sort(arr, start, mid);
		merge_sort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}