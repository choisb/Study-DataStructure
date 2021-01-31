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
int GetParentIDX(int idx)   // �θ� ����� index ��ȯ
{
    return idx / 2;
}
int GetLChildIDX(int idx)   // ���� �ڽ� ����� index ��ȯ
{
    return idx * 2;
}
int GetRChildIDX(int idx)   // ������ �ڽ� ����� index ��ȯ
{
    return idx * 2 + 1;
}
// �켱������ �� ���� �ڽ� ����� �ε��� ��ȯ
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