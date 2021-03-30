#ifndef __USEFULL_HEAP_H__
#define __USEFULL_HEAP_H__

#include "ALEdge.h"

#define TRUE    1
#define FALSE   0

#define HEAP_LEN    100

typedef Edge HData;
typedef int (*PriorityComp) (HData, HData);


typedef struct _heap
{
    PriorityComp comp;    // 우선순위. 비교 함수 포인터
    int numOfData;
    HData heapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap * ph, PriorityComp comp);
int HIsEmpty(Heap * ph);

void HInsert(Heap * ph, HData data);
HData HDelete(Heap * ph);

#endif