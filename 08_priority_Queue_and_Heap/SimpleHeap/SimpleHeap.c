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
// �켱������ �� ���� �ڽ� ����� �ε����� ��ȯ
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

// ���� ������ ����
// ���� ���� ������ �ڸ��� ���ο� ��带 ������ ��ġ�� ã�ư��� ���.
void HInsert(Heap * ph, HData data, Priority pr)
{
    int idx = ph->numOfData + 1;    // �� ��尡 ����� �ε��� ���� idx�� ����
    HeapElem nelem = { pr, data };  // �� ����� ���� �� �ʱ�ȭ

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
// ���� ������ ���� , ������ ��带 ��Ʈ���� �ø� �� �ڽ��� ��ġ�� ã�ư��� ���
HData HDelete(Heap * ph)
{
    HData retData = (ph->heapArr[1]).data;          // ��ȯ�� ���ؼ� ������ ������ ����
    HeapElem lastElem = ph->heapArr[ph->numOfData]; // ���� ������ ��� ����

    // ������ ��尡 ���� ���ؼ� ���� �ִ� �ڸ�(index)
    int currentIdx = 1;
    // ������ ��尡 ���� ���ؼ� ���� �ִ� �ڸ��� �ڽ� ��� �ڸ�(index)
    int childIdx;

    // ��Ʈ ����� �켱������ ���� �ڽ� ��带 �������� �ݺ��� ����
    while (childIdx = GetHiPriChildIDX(ph, currentIdx))
    {
        // ������ ����� �켱������ �ڽ� ����� �켱���� ���� ������� break;
        // ���Ⱑ ������ ��尡 �� ��ġ�� �ȴ�.
        if (lastElem.pr <= ph->heapArr[childIdx].pr)
            break;

        // �ڽĳ�尡 ������ ��庸�� �켱������ ���ٸ�
        // ���� ��ġ�� �ڽĳ�带 ����
        ph->heapArr[currentIdx] = ph->heapArr[childIdx];
        currentIdx = childIdx;
    }

    ph->heapArr[currentIdx] = lastElem;
    ph->numOfData--;
    return retData;
}