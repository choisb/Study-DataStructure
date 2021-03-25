#include <stdio.h>

// arr[a], arr[b], arr[c] �� �߰����� �ش��ϴ� index�� ��ȯ
int midIdx3(int arr[], int a, int b, int c)
{
	if (arr[a] >= arr[b])
		if (arr[b] >= arr[c])
			return b;
		else if (arr[a] <= arr[c])
			return a;
		else
			return c;

	else if (arr[a] >= arr[c])
		return a;
	else if (arr[b] >= arr[c])
		return c;
	else
		return b;			
}

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
	int pivotIdx = midIdx3(arr, left, right, (int)(left + right) / 2);
	int pivot = arr[pivotIdx];	// �ǹ��� ��ġ�� ���� ����!
	
	int low = left + 1;
	int high = right;

	printf("�ǹ�: %d\n", pivot);
	   
	while (low <= high) // �������� �ʾҴٸ�
	{
		while (pivot >= arr[low] && // low�� pivot���� ū ���� �߰��� ������ low++
			low <= high) // low�� high�� �Ѿ Ž���� �ʿ� ����.
			low++;

		while (pivot <= arr[high] && //high�� pivot���� ���� ���� �߰��� ������ high--
			low <= high)// high�� low�� �Ѿ Ž���� �ʿ� ����.
			high--;

		if(low <= high)
			Swap(arr, low, high);
	}

	Swap(arr, pivotIdx, high); // �ǹ��� high�� ����Ű�� ��� ��ȯ, high�� �׻� pivot���� ���� ���� ������.
	return high; // �Ű��� �ǹ��� ��ġ���� ��ȯ
}

void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);	// �ѷ� ������
		QuickSort(arr, left, pivot - 1);			// ���� ������ ����
		QuickSort(arr, pivot + 1, right);			// ������ ������ ����
	}
}
int main(void)
{
	int arr[11] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	int len = sizeof(arr) / sizeof(int);
	int i;

	QuickSort(arr, 0, len - 1);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}