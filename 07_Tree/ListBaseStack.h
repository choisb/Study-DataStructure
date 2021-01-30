#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#include "BinaryTree.h"

#define TRUE        1
#define FALSE       0

typedef BTreeNode * Data;

typedef struct _node {
    Data data;
    struct _node * next;
}Node;

typedef struct _ListStack
{
    Node* head;
}ListStack;

typedef ListStack Stack;

void StackInit(Stack * pstack);         // ������ �ʱ�ȭ
int SIsEmpty(Stack * pstack);           // ������ ������� Ȯ��

void SPush(Stack * pstack, Data data);  // ������ push ����
Data SPop(Stack * pstack);              // ������ pop ����
Data SPeek(Stack * pstack);             // ������ peek ����

#endif