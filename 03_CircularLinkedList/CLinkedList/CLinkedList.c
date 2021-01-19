#include "CLinkedList.h"
#include <stdio.h>

void ListInit(List * plist)
{
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numOfData = 0;
}

void LInsert(List * plist, LData data) // ������ ��� �߰�
{
    LInsertFront(plist, data);

    plist->tail = plist->tail->next;    // ������ ��� �߰��ϴ� ���� �ᱹ �Ӹ��� ��带 �߰��� �Ϳ� tail�� ����Ű�� ��带 ��ĭ ������ �̵��� ����� �����ϴ�.
}
void LInsertFront(List * plist, LData data) // �Ӹ��� ��带 �߰�
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (plist->tail == NULL) // ù ��° ��� ����
    {
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
    }
    (plist->numOfData)++;
}
int LFirst(List * plist, LData * pdata)
{
    if (plist->tail == NULL)
        return FALSE;
    plist->before = plist->tail;
    plist->cur = plist->tail->next;

    *pdata = plist->cur->data;
    return TRUE;
}
int LNext(List * plist, LData * pdata)
{
    if (plist->tail == NULL) //����� ��尡 ���ٸ�.
        return FALSE;

    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
    
}
LData LRemove(List * plist)
{
    LData rdata = plist->cur->data;
    Node* rpos = plist->cur;
    if (plist->tail == NULL)
        return FALSE;
   
    // ��带 �����Ҷ� �ΰ��� ���ܸ� ����� �Ѵ�.
    // 1. ������ ��带 tail�� ����Ű�� ���
    // 2. ������ ��尡 ����Ʈ�� Ȧ�� ���� ���
    if (plist->tail == rpos)
    {
        if (plist->tail == plist->tail->next)   //tail�� ������ ���� �����鼭, tail�� tail->�� ���ٴ� ���� "2.������ ��尡 ����Ʈ�� Ȧ�� ���� ��� �̴�."
            plist->tail = NULL;                 // ������ ��尡 Ȧ�� ���ұ� ������ tail�� �ٽ� NULL�� �����Ѿ� �Ѵ�.

        else                                    //�� ��Ȳ�� �ƴ϶��, ����Ʈ�� ���� ������ ���� "1. ������ ��带 tail�� ����Ű�� ���"�� ���̴�.
            plist->tail = plist->before;        // �̶��� tail�� ����Ű�� ����� before ���� �ű��.
    }

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;
 
    free(rpos);
    (plist->numOfData)--;
    return rdata;

}
int LCount(List * plist)
{
    return plist->numOfData;
}
