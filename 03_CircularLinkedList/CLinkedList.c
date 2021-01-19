#include "CLinkedList.h"
#include <stdio.h>

void ListInit(List * plist)
{
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numOfData = 0;
}

void LInsert(List * plist, LData data) // 꼬리에 노드 추가
{
    LInsertFront(plist, data);

    plist->tail = plist->tail->next;    // 꼬리에 노드 추가하는 것은 결국 머리에 노드를 추가한 것에 tail이 가리키는 노드를 한칸 옆으로 이동한 결과와 동일하다.
}
void LInsertFront(List * plist, LData data) // 머리에 노드를 추가
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (plist->tail == NULL) // 첫 번째 노드 삽입
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
    if (plist->tail == NULL) //저장된 노드가 없다면.
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
   
    // 노드를 삭제할때 두가지 예외를 살펴야 한다.
    // 1. 삭제할 노드를 tail이 가리키는 경우
    // 2. 삭제할 노드가 리스트에 홀로 남은 경우
    if (plist->tail == rpos)
    {
        if (plist->tail == plist->tail->next)   //tail이 삭제할 노드와 같으면서, tail이 tail->와 같다는 뜻은 "2.삭제할 노드가 리스트에 홀로 남은 경우 이다."
            plist->tail = NULL;                 // 삭제할 노드가 홀로 남았기 때문에 tail은 다시 NULL을 가리켜야 한다.

        else                                    //위 상황이 아니라면, 리스트에 노드는 많은데 하필 "1. 삭제할 노드를 tail이 가리키는 경우"인 것이다.
            plist->tail = plist->before;        // 이때는 tail이 가리키는 대상을 before 노드로 옮긴다.
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
