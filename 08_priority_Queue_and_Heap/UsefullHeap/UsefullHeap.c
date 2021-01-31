#include "UsefullHeap.h"

void HeapInit(Heap * ph, PriorityComp comp)
{
    ph->numOfData = 0;
    ph->comp = comp;
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
// 우선순위가 더 높은 자식 노드의 인덱스 반환
int GetHiPriChildIDX(Heap * ph, int idx)
{
    if (GetLChildIDX(idx) > ph->numOfData)
        return 0;
    else if (GetLChildIDX(idx) == ph->numOfData)
        return GetLChildIDX(idx);
    else
    {
        if (ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) < 0)
            return GetRChildIDX(idx);
        else
            return GetLChildIDX(idx);
    }
}

void HInsert(Heap * ph, HData data)
{
    int idx = ph->numOfData + 1;
    while (idx != 1)
    {
        if (ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0)
        {
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx);
        }
        else
        {
            break;
        }
    }

    ph->heapArr[idx] = data;
    ph->numOfData += 1;
}

HData HDelete(Heap * ph)
{
    HData retData = ph->heapArr[1];
    HData lastElem = ph->heapArr[ph->numOfData];

    int currentIdx = 1;
    int childIdx;

    while (childIdx = GetHiPriChildIDX(ph, currentIdx)) 
    {
        if (ph->comp(lastElem, ph->heapArr[currentIdx]) < 0)
        {
            ph->heapArr[currentIdx] = ph->heapArr[childIdx];
            currentIdx = childIdx;
        }
        else
        {
            break;
        }
    }
    ph->heapArr[currentIdx] = lastElem;
    ph->numOfData -= 1;
    return retData;
}