#ifndef __C_LINKED_LIST_H__
#define __c_LINKED_LIST_H__

#define TRUE    1
#define FALSE   0

typedef int LData;

typedef struct _node
{
    LData data;
    struct _node * next;
}Node;

typedef struct _CLL
{
    Node * tail;
    Node * cur;
    Node * before;
    int numOfData;
}CList;

typedef CList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);      // 꼬리에 노드를 추가
void LInsertFront(List * plist, LData data); // 머리에 노드를 추가

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);
LData LRemove(List * plist);
int LCount(List * plist);

#endif
