#include "DBLinkedList.h"
#include <stdio.h>

void ListInit(List * plist)
{
    plist->cur = NULL;
    plist->head = NULL;
    plist->numOfData = 0;
}
void LInsert(List * plist, LData data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (plist->head != NULL)            // ����Ʈ�� ��尡 �����Ѵٸ�
        plist->head->prev = newNode;    // head�� �ִ� ����� prev�� newNode�� �����Ѵ�.

    newNode->next = plist->head;        // newNode�� next�� ���� head ��带 ����Ų��.
    newNode->prev = NULL;
    plist->head = newNode;          

    (plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata)
{
    if (plist->head == NULL)
        return FALSE;

    plist->cur = plist->head;   // ���� ���Ḯ��Ʈ������ cur �ϳ��� �̵��ϸ� ��. (before�� ��� �ȴ�.)
    *pdata = plist->cur->data;

    return TRUE;
}

int LNext(List * plist, LData * pdata)
{
    if (plist->cur->next == NULL)
        return FALSE;

    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;

    return TRUE;
}
int LPrevious(List * plist, LData * pdata)
{
    if (plist->cur->prev == NULL)
        return FALSE;

    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;

    return TRUE;
}
LData LRemove(List * plist)
{
    Node* rpos = plist->cur; 
    LData rdata = rpos->data;

    // ����Ʈ�� ���� ��� ���� ���
    if (plist->cur->prev == NULL && plist->cur->next == NULL)   
    {
        plist->head = NULL;
        plist->cur = NULL;
    }
    // ���� ��尡 ����Ʈ�� ���� �տ� �ִ� ���
    else if (plist->cur->prev == NULL)  
    {
        plist->head = plist->cur->next;
        plist->cur->next->prev = NULL;

        plist->cur = plist->head;
    }
    // ���� ��尡 ����Ʈ�� ���� �ڿ� �ִ� ���
    else if (plist->cur->next == NULL)  
    {
        plist->cur->prev->next = NULL;

        plist->cur = plist->cur->prev;
    }
    // ���� ����� �յڷ� ��尡 �ִ� ���
    else 
    {
        plist->cur->prev->next = rpos->next;
        plist->cur->next->prev = rpos->prev;

        plist->cur = plist->cur->prev;
    }

    // ��带 �޸𸮿��� ����
    free(rpos);

    (plist->numOfData)--;
    return rdata;
}
int LCount(List * plist)
{
    return plist->numOfData;
}