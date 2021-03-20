#include <stdio.h>

void InserSort(int arr[], int n)
{
	int i, j;
	int insData;

	for (i = 1; i < n; i++)
	{
		insData = arr[i];

		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > insData)
				arr[j + 1] = arr[j];	// 비교대상 한 칸 뒤로 밀기
			else
				break;	// 삽입위치 발견시 반복문 종료
		}
		arr[j + 1] = insData;
	}
}

int main(void)
{
	int arr[5] = { 5,3,2,4,1 };
	int i;

	InserSort(arr, sizeof(arr) / sizeof(int));

	for (i = 0; i < 5; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}