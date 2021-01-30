#include "SimpleHeap.h"
#include <stdlib.h>

void HeapInit(Heap * ph)
{
    ph->numOfData = 0;
}
int HIsEmpty(Heap * ph)
{
    return ph->numOfData == 0;
}
int GetParentIDX(int idx)   // 부모 노드의 index 반환
{
    return idx / 2;
}
int GetLChildIDX(int idx)   // 왼쪽 자식 노드의 index 반환
{
    return idx * 2;
}
int GetRChildIDX(int idx)   // 오른쪽 자식 노드의 index 반환
{
    return idx * 2 + 1;
}
// 우선순위가 더 높은 자식 노드의 인덱스를 반환
int GetHiPriChildIDX(Heap * ph, int idx)
{
    if (GetLChildIDX(idx) > ph->numOfData)
        return 0;
    else if (GetLChildIDX(idx) == ph->numOfData)
        return GetLChildIDX(idx);
    else
    {
        if (ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
            return GetRChildIDX(idx);
        else
            return GetLChildIDX(idx);
    }
}

// 힙에 데이터 삽입
// 힙의 가장 마지막 자리에 새로운 노드를 삽입후 위치를 찾아가는 방법.
void HInsert(Heap * ph, HData data, Priority pr)
{
    int idx = ph->numOfData + 1;    // 새 노드가 저장될 인덱스 값을 idx에 저장
    HeapElem nelem = { pr, data };  // 새 노드의 생성 및 초기화

    while (idx != 1)
    {
        if (pr < (ph->heapArr[GetParentIDX(idx)].pr))
        {
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx);
        }
        else
            break;
    }

    ph->heapArr[idx] = nelem;
    ph->numOfData++;    
}
// 힙에 데이터 삭제 , 마지막 노드를 루트노드로 올린 후 자신의 위치를 찾아가는 방식
HData HDelete(Heap * ph)
{
    HData retData = (ph->heapArr[1]).data;          // 반환을 위해서 삭제할 데이터 저장
    HeapElem lastElem = ph->heapArr[ph->numOfData]; // 힙의 마지막 노드 저장

    // 마지막 노드가 들어가기 위해서 보고 있는 자리(index)
    int currentIdx = 1;
    // 마지막 노드가 들어가기 위해서 보고 있는 자리의 자식 노드 자리(index)
    int childIdx;

    // 루트 노드의 우선순위가 높은 자식 노드를 시작으로 반복문 시작
    while (childIdx = GetHiPriChildIDX(ph, currentIdx))
    {
        // 마지막 노드의 우선순위가 자식 노드의 우선순위 보다 높을경우 break;
        // 여기가 마지막 노드가 들어갈 위치가 된다.
        if (lastElem.pr <= ph->heapArr[childIdx].pr)
            break;

        // 자식노드가 마지막 노드보다 우선순위가 높다면
        // 지금 위치에 자식노드를 저장
        ph->heapArr[currentIdx] = ph->heapArr[childIdx];
        currentIdx = childIdx;
    }

    ph->heapArr[currentIdx] = lastElem;
    ph->numOfData--;
    return retData;
}