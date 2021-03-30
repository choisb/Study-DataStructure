#include "ArrayBaseStack.h"

void StackInit(Stack * pstack)
{
    pstack->topIndex = -1;  // topIndex�� -1�� �� ���¸� �ǹ�
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

    if (SIsEmpty(pstack)) {    // Stack�� ����ٸ� �޸� ���� ����!
        printf("Stack Memory Error!");
        exit(-1);
    }

    rData = pstack->stackArr[pstack->topIndex];
    pstack->topIndex--;

    return rData;
}
Data SPeek(Stack * pstack)
{
    if (SIsEmpty(pstack)) {    // Stack�� ����ٸ� �޸� ���� ����!
        printf("Stack Memory Error!");
        exit(-1);
    }

    return pstack->stackArr[pstack->topIndex];
}