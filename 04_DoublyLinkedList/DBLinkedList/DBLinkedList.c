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

    if (plist->head != NULL)            // 리스트에 노드가 존재한다면
        plist->head->prev = newNode;    // head에 있던 노드의 prev를 newNode로 연결한다.

    newNode->next = plist->head;        // newNode의 next는 이제 head 노드를 가리킨다.
    newNode->prev = NULL;
    plist->head = newNode;          

    (plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata)
{
    if (plist->head == NULL)
        return FALSE;

    plist->cur = plist->head;   // 이중 연결리스트에서는 cur 하나만 이동하면 됨. (before은 없어도 된다.)
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

    // 리스트에 현재 노드 뿐인 경우
    if (plist->cur->prev == NULL && plist->cur->next == NULL)   
    {
        plist->head = NULL;
        plist->cur = NULL;
    }
    // 현재 노드가 리스트의 가장 앞에 있는 경우
    else if (plist->cur->prev == NULL)  
    {
        plist->head = plist->cur->next;
        plist->cur->next->prev = NULL;

        plist->cur = plist->head;
    }
    // 현재 노드가 리스트의 가장 뒤에 있는 경우
    else if (plist->cur->next == NULL)  
    {
        plist->cur->prev->next = NULL;

        plist->cur = plist->cur->prev;
    }
    // 현재 노드의 앞뒤로 노드가 있는 경우
    else 
    {
        plist->cur->prev->next = rpos->next;
        plist->cur->next->prev = rpos->prev;

        plist->cur = plist->cur->prev;
    }

    // 노드를 메모리에서 해제
    free(rpos);

    (plist->numOfData)--;
    return rdata;
}
int LCount(List * plist)
{
    return plist->numOfData;
}