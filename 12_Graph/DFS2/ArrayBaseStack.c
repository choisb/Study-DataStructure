#include "ArrayBaseStack.h"

void StackInit(Stack * pstack)
{
    pstack->topIndex = -1;  // topIndex의 -1은 빈 상태를 의미
}
int SIsEmpty(Stack * pstack)
{
    return pstack->topIndex == -1;
}
void SPush(Stack * pstack, Data data)
{
    pstack->topIndex++;
    pstack->stackArr[pstack->topIndex] = data;
}
Data SPop(Stack * pstack)
{
    Data rData;

    if (SIsEmpty(pstack)) {    // Stack이 비었다면 메모리 접근 에러!
        printf("Stack Memory Error!");
        exit(-1);
    }

    rData = pstack->stackArr[pstack->topIndex];
    pstack->topIndex--;

    return rData;
}
Data SPeek(Stack * pstack)
{
    if (SIsEmpty(pstack)) {    // Stack이 비었다면 메모리 접근 에러!
        printf("Stack Memory Error!");
        exit(-1);
    }

    return pstack->stackArr[pstack->topIndex];
}