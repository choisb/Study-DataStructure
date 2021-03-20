#include <stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];	// �ǹ��� ��ġ�� ���� ����!
	int low = left + 1;
	int high = right;

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

	Swap(arr, left, high); // �ǹ�(left)�� high�� ����Ű�� ��� ��ȯ, high�� �׻� pivot���� ���� ���� ������.
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
	int arr[3] = { 3, 3, 3 };
	int len = sizeof(arr) / sizeof(int);
	int i;

	QuickSort(arr, 0, len - 1);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}