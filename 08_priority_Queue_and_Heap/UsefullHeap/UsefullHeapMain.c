#include <stdio.h>
#include "UsefullHeap.h"

int DataPriorityComp(char ch1, char ch2)
{
    return ch2 - ch1;
}

int main(void)
{
    Heap heap;
    HeapInit(&heap, DataPriorityComp);

    HInsert(&heap, 'A');
    HInsert(&heap, 'B');
    HInsert(&heap, 'C');

    printf("Delete %c \n", HDelete(&heap));

    HInsert(&heap, 'A');
    HInsert(&heap, 'B');
    HInsert(&heap, 'C');
    HInsert(&heap, 'D');

    printf("Delete %c \n", HDelete(&heap));

    while (!HIsEmpty(&heap))
        printf("%c \n", HDelete(&heap));

    return 0;
}