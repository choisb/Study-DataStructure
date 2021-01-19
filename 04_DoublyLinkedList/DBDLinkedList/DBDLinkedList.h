#ifndef __DB_DLINKED_LIST_H__
#define __DB_DLINKED_LIST_H__

#define TRUE    1;
#define FALSE   0;

typedef int LData;

typedef struct _node
{
    LData data;
    struct _node * next;
    struct _node * prev;

}Node;

typedef struct _DLinkedList
{
    Node * head;
    Node * tail;
    Node * cur;
    int numOfData;
}DBDLinkedList;

typedef DBDLinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);
int LPrevious(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

#endif