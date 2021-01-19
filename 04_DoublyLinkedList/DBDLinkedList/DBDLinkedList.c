#include "DBDLinkedList.h"
#include <stdio.h>

void ListInit(List * plist)
{
    plist->cur = NULL;

    plist->head = (Node*)malloc(sizeof(Node));  // head �� ���� ���
    plist->tail = (Node*)malloc(sizeof(Node));  // tail �� ���� ���

    plist->head->prev = NULL;           // head�� prev�� �׻� NULL
    plist->head->next = plist->tail;    // ���� ��尣 ����

    plist->tail->prev = plist->head;    // ���� ��尣 ����
    plist->tail->next = NULL;           // tail�� next�� �׻� NULL

    plist->numOfData = 0;
}
void LInsert(List * plist, LData data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    // head ���̳��� tail ���̳�尡 �����ϱ� ������
    // head->next�� tail->prev�� �׻� NULL�� �ƴ��� ������� �� �ִ�.
    // ���ٸ� ����ó���� �ʿ� ����.

    newNode->next = plist->head->next;        // newNode�� next�� head ���� ����� next�� ����Ų��.
    newNode->prev = plist->head;              // newNode�� prev�� head ���� ��带 ����Ų��.
    plist->head->next->prev = newNode;        // head ������ next ����� prev�� newNode�� ����Ų��.
    plist->head->next = newNode;              // head ������ next�� newNode�� ����Ų��.

    (plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata)
{
    if (plist->head->next == plist->tail)    // ����Ʈ�� ���̳��ۿ� ���� ���
        return FALSE;

    plist->cur = plist->head->next;   // ���� ���Ḯ��Ʈ������ cur �ϳ��� �̵��ϸ� ��. (before�� ��� �ȴ�.)
    *pdata = plist->cur->data;

    return TRUE;
}

int LNext(List * plist, LData * pdata)
{
    if (plist->cur == plist->tail)  // LRemove()���� cur�� head ���̷� �Ű��� �� �ֱ⶧���� ����Ȯ��.
        return FALSE;
    if (plist->cur->next == plist->tail) // ������ ���� ��尡 ���̳���� ���
        return FALSE;

    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;

    return TRUE;
}
int LPrevious(List * plist, LData * pdata)
{
    //plist->cur�� head�� ���̳���� ���.
    if (plist->cur == plist->head)  // LRemove()���� cur�� head ���̷� �Ű��� �� �ֱ⶧���� ����Ȯ��.
        return FALSE;
    if (plist->cur->prev == plist->head) // ������ ���� ��尡 ���̳���� ���
        return FALSE;

    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;

    return TRUE;
}
LData LRemove(List * plist)
{
    // head ���̳��� tail ���̳�尡 �����ϱ� ������
    // cur->next�� cur->prev�� �׻� NULL�� �ƴ��� ������� �� �ִ�.
    // ���� ���ٸ� ����ó���� �ʿ� ����.

    Node* rpos = plist->cur;
    LData rdata = rpos->data;

    plist->cur->prev->next = plist->cur->next;
    plist->cur->next->prev = plist->cur->prev;

    plist->cur = plist->cur->prev;
    free(rpos);

    (plist->numOfData)--;
    return rdata;
}
int LCount(List * plist)
{
    return plist->numOfData;
}