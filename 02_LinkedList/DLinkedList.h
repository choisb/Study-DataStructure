#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_lIST_H__

#define TRUE    1
#define FALSE   0

typedef int LData;

typedef struct _node
{
    LData data;
    struct _node * next;
}Node;

typedef struct _linkedList
{
    Node * head;
    Node * cur;
    Node * before;
};
#endif