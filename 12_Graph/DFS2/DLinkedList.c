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

void FInsert(List * plist, LData data) //사용자가 호출 할 수 없는 함수. 오직 LInsert()에서 호출 함. C++로 예를들면 private과 비슷한 개념.
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->head->next;
    plist->head->next = newNode;

    (plist->numOfData)++;
}

void SInsert(List * plist, LData data) //사용자가 호출 할 수 없는 함수. 오직 LInsert()에서 호출 함. C++로 예를들면 private과 비슷한 개념.
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    Node* pred = plist->head;

    newNode->data = data;

    // pred->next가 NULL이 아니고,
    // data가 pred->next->data 보다 뒤에 있어야 할때.
    // comp함수에서 두개의 인자 'data'와 'pred->next->data' 중 'data'가 head와 더 가까워야 한다면 0을 반환한다. 
    // 즉, 0이 아니라면, 'data'는 더 뒤에 있어야 한다는 뜻이다.
    // pred->next가 NULL일 수 있기 때문에 반드시 pred->next->data 검사 전에 NULL체크 구문이 먼저 들어가야한다.
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
        FInsert(plist, data);   //comp 함수가 등록되지 않았을 경우, 첫 번째 노드 삽입
    else
        SInsert(plist, data);   //comp 함수가 등록되어 있는 경우, comp노드 정렬 기준에 맞는 위치에 노드 삽입.
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