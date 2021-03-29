#include "DLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List * plist)
{
    plist->head = (Node*)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->cur = plist->head;
    plist->before = plist->head;

    plist->numOfData = 0;
    plist->comp = NULL;
}

void FInsert(List * plist, LData data) //����ڰ� ȣ�� �� �� ���� �Լ�. ���� LInsert()���� ȣ�� ��. C++�� ������� private�� ����� ����.
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->head->next;
    plist->head->next = newNode;

    (plist->numOfData)++;
}

void SInsert(List * plist, LData data) //����ڰ� ȣ�� �� �� ���� �Լ�. ���� LInsert()���� ȣ�� ��. C++�� ������� private�� ����� ����.
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    Node* pred = plist->head;

    newNode->data = data;

    // pred->next�� NULL�� �ƴϰ�,
    // data�� pred->next->data ���� �ڿ� �־�� �Ҷ�.
    // comp�Լ����� �ΰ��� ���� 'data'�� 'pred->next->data' �� 'data'�� head�� �� ������� �Ѵٸ� 0�� ��ȯ�Ѵ�. 
    // ��, 0�� �ƴ϶��, 'data'�� �� �ڿ� �־�� �Ѵٴ� ���̴�.
    // pred->next�� NULL�� �� �ֱ� ������ �ݵ�� pred->next->data �˻� ���� NULLüũ ������ ���� �����Ѵ�.
    while (pred->next != NULL && plist->comp(data, pred->next->data) != 0)
    {
        pred = pred->next;
    }

    newNode->next = pred->next;
    pred->next = newNode;

    (plist->numOfData)++;
}

void LInsert(List * plist, LData data)
{
    if (plist->comp == NULL)
        FInsert(plist, data);   //comp �Լ��� ��ϵ��� �ʾ��� ���, ù ��° ��� ����
    else
        SInsert(plist, data);   //comp �Լ��� ��ϵǾ� �ִ� ���, comp��� ���� ���ؿ� �´� ��ġ�� ��� ����.
}

int LFirst(List * plist, LData * pData) 
{
    if (plist->head->next == NULL)
        return FALSE;

    plist->before = plist->head;
    plist->cur = plist->head->next;
    
    *pData = plist->cur->data;
    return TRUE;
}
int LNext(List * plist, LData * pData)
{
    if (plist->cur->next == NULL)
        return FALSE;

    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pData = plist->cur->data;
    return TRUE;
}
LData LRemove(List * plist)
{
    if (plist->cur == plist->before)
        return FALSE;

    Node * rpos = plist->cur;
    LData rdata = plist->cur->data;

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

void SetSortRule(List * plist, int(*comp)(LData d1, LData d2))
{
    plist->comp = comp;
}