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

    rnode = pstack->head->next;         // ������ ����� �ּҰ��� �ӽ÷� ����
    rdata = rnode->data;                // ������ ����� �����͸� �ӽ÷� ����

    pstack->head->next = rnode->next;   // ������ ����� ���� ��带 head�� ����Ŵ
    free(rnode);    // ��� ����
    return rdata;   // ������ ����� ������ ��ȯ
}
Data SPeek(Stack * pstack)
{
    if (SIsEmpty(pstack)) {
        printf("Stack Memory Error!");
        exit(-1);
    }

    return pstack->head->next->data;    // head�� ����Ű�� ��忡 ����� ������ ��ȯ
}