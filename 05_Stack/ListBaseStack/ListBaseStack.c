#include <stdio.h>
#include "ListBaseStack.h"

void StackInit(Stack * pstack)
{
    pstack->head = (Node*)malloc(sizeof(Node));
    pstack->head->next = NULL;
}
int SIsEmpty(Stack * pstack)
{
    return pstack->head->next == NULL;
}

void SPush(Stack * pstack, Data data)
{
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
 
    newNode->data = data;
    newNode->next = pstack->head->next;

    pstack->head->next = newNode;
}
Data SPop(Stack * pstack)
{
    Node* rnode;
    Data rdata;
    if (SIsEmpty(pstack)) {
        printf("Stack Memory Error!");
        exit(-1);
    }

    rnode = pstack->head->next;         // 삭제할 노드의 주소값을 임시로 저장
    rdata = rnode->data;                // 삭제할 노드의 데이터를 임시로 저장

    pstack->head->next = rnode->next;   // 삭제할 노드의 다음 노드를 head가 가리킴
    free(rnode);    // 노드 삭제
    return rdata;   // 삭제된 노드의 데이터 반환
}
Data SPeek(Stack * pstack)
{
    if (SIsEmpty(pstack)) {
        printf("Stack Memory Error!");
        exit(-1);
    }

    return pstack->head->next->data;    // head가 가리키는 노드에 저장된 데이터 반환
}