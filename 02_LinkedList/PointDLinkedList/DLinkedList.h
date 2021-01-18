#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_lIST_H__

#include "Point.h"

#define TRUE    1
#define FALSE   0

typedef Point* LData;

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
    int numOfData;
    int(*comp)(LData d1, LData d2);
}LinkedList;

typedef LinkedList List;

void ListInit(List * plist);
// �ʱ�ȭ�� ����Ʈ�� �ּ� ���� ���ڷ� �����Ѵ�.
// ����Ʈ ���� �� ���� ���� ȣ��Ǿ�� �ϴ� �Լ��̴�.

void LInsert(List * plist, LData data);
// ����Ʈ�� �����͸� �����Ѵ�. �Ű����� data�� ���޵� ���� �����Ѵ�.

int LFirst(List * plist, LData * pdata);
// ù ��° �����Ͱ� pdata�� ����Ű�� �޸𸮿� ����ȴ�.
// �������� ������ ���� �ʱ�ȭ�� ����ȴ�.
// ���� ���� �� TRUE(1), ���н� FALSE(0)��ȯ

int LNext(List * plist, LData * pdata);
// ������ �������� ���� �����Ͱ� pdata�� ����Ű�� �޸𸮿� ����ȴ�.
// �������� ������ ���ؼ� �ݺ� ȣ���� �����ϴ�.
// ������ ���� �����Ϸ��� ���� LFirst �Լ��� ȣ���ؾ� �Ѵ�.
// ���� ���� �� TRUE(1), ���� �� FALSE(0) ��ȯ

LData LRemove(List * pdata);
// LFirst �Ǵ� LNext �Լ��� ������ ��ȯ �����͸� �����Ѵ�.
// ������ �����ʹ� ��ȯ�ȴ�.
// ������ ��ȯ �����͸� �����ϹǷ� ������ �ݺ� ȣ���� ������� �ʴ´�.

int LCount(List * plist);
// ����Ʈ�� ����Ǿ� �ִ� �������� ���� ��ȯ�Ѵ�.

void SetSortRule(List * plist, int(*comp)(LData d1, LData d2));
// ����Ʈ�� ������ ������ �Ǵ� �Լ��� ����Ѵ�.


#endif