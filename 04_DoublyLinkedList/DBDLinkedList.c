#include "DBDLinkedList.h"
#include <stdio.h>

void ListInit(List * plist)
{
    plist->cur = NULL;

    plist->head = (Node*)malloc(sizeof(Node));  // head 의 더미 노드
    plist->tail = (Node*)malloc(sizeof(Node));  // tail 의 더미 노드

    plist->head->prev = NULL;           // head의 prev는 항상 NULL
    plist->head->next = plist->tail;    // 더미 노드간 연결

    plist->tail->prev = plist->head;    // 더미 노드간 연결
    plist->tail->next = NULL;           // tail의 next는 항상 NULL

    plist->numOfData = 0;
}
void LInsert(List * plist, LData data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    // head 더미노드와 tail 더미노드가 존재하기 때문에
    // head->next와 tail->prev는 항상 NULL이 아님을 보장받을 수 있다.
    // 별다른 예외처리가 필요 없다.

    newNode->next = plist->head->next;        // newNode의 next는 head 더미 노드의 next를 가리킨다.
    newNode->prev = plist->head;              // newNode의 prev는 head 더미 노드를 가리킨다.
    plist->head->next->prev = newNode;        // head 더미의 next 노드의 prev는 newNode를 가리킨다.
    plist->head->next = newNode;              // head 더미의 next는 newNode를 가리킨다.

    (plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata)
{
    if (plist->head->next == plist->tail)    // 리스트에 더미노드밖에 없는 경우
        return FALSE;

    plist->cur = plist->head->next;   // 이중 연결리스트에서는 cur 하나만 이동하면 됨. (before은 없어도 된다.)
    *pdata = plist->cur->data;

    return TRUE;
}

int LNext(List * plist, LData * pdata)
{
    if (plist->cur == plist->tail)  // LRemove()에서 cur가 head 더미로 옮겨질 수 있기때문에 예외확인.
        return FALSE;
    if (plist->cur->next == plist->tail) // 현재의 다음 노드가 더미노드인 경우
        return FALSE;

    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;

    return TRUE;
}
int LPrevious(List * plist, LData * pdata)
{
    //plist->cur이 head의 더미노드인 경우.
    if (plist->cur == plist->head)  // LRemove()에서 cur가 head 더미로 옮겨질 수 있기때문에 예외확인.
        return FALSE;
    if (plist->cur->prev == plist->head) // 현재의 이전 노드가 더미노드인 경우
        return FALSE;

    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;

    return TRUE;
}
LData LRemove(List * plist)
{
    // head 더미노드와 tail 더미노드가 존재하기 때문에
    // cur->next와 cur->prev는 항상 NULL이 아님을 보장받을 수 있다.
    // 따라서 별다른 예외처리가 필요 없다.

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