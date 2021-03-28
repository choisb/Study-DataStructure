#ifndef __TABLE2_H__
#define __TABLE2_H__

#include "Slot2.h"
#include "DLinkedList.h"

#define MAX_TBL	100

typedef int HashFunc (Key k);

typedef struct _table
{
	List tbl[MAX_TBL];
	HashFunc* hf;

}Table;

// ���̺��� �ʱ�ȭ, ����ڷ� ���� �ؽ��Լ��� ��Ϲ޴´�
void TBLInit(Table * pt, HashFunc * f);

// ���̺� Ű�� ���� ����
void TBLInsert(Table * pt, Key k, Value v);

// Ű�� �ٰŷ� ���̺��� ������ ����
Value TBLDelete(Table * pt, Key k);

// Ű�� �ٰŷ� ���̺��� ������ Ž��
Value TBLSearch(Table * pt, Key k);

#endif