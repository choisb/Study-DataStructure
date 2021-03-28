#include <stdio.h>
#include <stdlib.h>
#include "Table2.h"

void TBLInit(Table * pt, HashFunc * f)
{
	int i;

	// ��� ���� �ʱ�ȭ
	for (i = 0; i < MAX_TBL; i++)
		ListInit(&(pt->tbl[i]));

	pt->hf = f;
}

void TBLInsert(Table * pt, Key k, Value v)
{
	int hv = pt->hf(k);

	// ���� ����
	Slot * ns = (Slot*) malloc (sizeof(Slot));
	ns->key = k;
	ns->val = v;

	// Ű�� �ߺ��ȴٸ�
	if (TBLSearch(pt, k) != NULL)
	{
		printf("Ű �ߺ� ���� �߻� \n");
		return;
	}
	else
	{
		LInsert(&(pt->tbl[hv]), ns);
	}
}

Value TBLDelete(Table * pt, Key k)
{
	int hv = pt->hf(k);
	LData cSlot;
	Value dVal;

	// tbl[hv] ����Ʈ�� ù��° ������ ����ִٸ� FALSE ��ȯ
	// tbl[hv] ����Ʈ�� ù��° ������ ������� �ʴٸ�,
	// cSlot�� ù��° ���� �ּҰ� ������ TRUE ��ȯ
	if (LFirst(&(pt->tbl[hv]), &cSlot))
	{
		do
		{
			if ((cSlot->key == k)) {
				dVal = cSlot->val;
				// ������ �޸𸮿��� ����
				free(cSlot);
				LRemove(&(pt->tbl[hv]));
				return dVal;
			}
		} while (LNext(&(pt->tbl[hv]), &cSlot));
	}

	// �ش� key���� �������� ���� ��� NULL ��ȯ
	return NULL;
}

Value TBLSearch(Table * pt, Key k)
{
	int hv = pt->hf(k);
	LData cSlot;

	if (LFirst(&(pt->tbl[hv]), &cSlot))
	{
		do
		{
			if (cSlot->key == k)
				return cSlot->val;

		} while (LNext(&(pt->tbl[hv]), &cSlot));
	}

	return NULL;
}