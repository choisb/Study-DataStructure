#include <stdio.h>

int ISearch(int ar[], int first, int last, int target)
{
	int mid;

	//target에 저장된 값이 first의 값보다 작거나, last의 값보다 클 경우 탐색 실패
	// 이진탐색과 차이점.(이진 탐색은 last < first 일경우만 탐색 실패로 봐도 되지만,
	// 보간탐색에서는 target이 first ~ last 범위를 초과하는 경우도 생길 수 있기 때문
	if (ar[first] > target || ar[last] < target)
		return -1;	// -1의 반환은 탐색의 실패를 의미

	// 이진 탐색과의 차이점을 반영한 문장
	// 탐색위치를 비례식을 통해서 계산
	mid = ((double)(target - ar[first])	/ (ar[last] - ar[first]) 
		* (last - first)) + first;
	printf("mid: %d\n", mid);

	if (ar[mid] == target)
		return mid;
	else if (target < ar[mid])
		return ISearch(ar, first, mid - 1, target);
	else
		return ISearch(ar, mid + 1, last, target);
}

int main(void)
{
	int arr[] = { 1, 3, 5, 7, 9 };
	int idx;

	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);

	if (idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);
	
	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 2);

	if (idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);

	return 0;
}