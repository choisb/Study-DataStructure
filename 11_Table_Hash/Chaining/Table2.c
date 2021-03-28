#include <stdio.h>
#include <stdlib.h>
#include "Table2.h"

void TBLInit(Table * pt, HashFunc * f)
{
	int i;

	// 모든 슬롯 초기화
	for (i = 0; i < MAX_TBL; i++)
		ListInit(&(pt->tbl[i]));

	pt->hf = f;
}

void TBLInsert(Table * pt, Key k, Value v)
{
	int hv = pt->hf(k);

	// 슬롯 생성
	Slot * ns = (Slot*) malloc (sizeof(Slot));
	ns->key = k;
	ns->val = v;

	// 키가 중복된다면
	if (TBLSearch(pt, k) != NULL)
	{
		printf("키 중복 오류 발생 \n");
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

	// tbl[hv] 리스트의 첫번째 슬롯이 비어있다면 FALSE 반환
	// tbl[hv] 리스트의 첫번째 슬롯이 비어있지 않다면,
	// cSlot에 첫번째 슬롯 주소값 저장후 TRUE 반환
	if (LFirst(&(pt->tbl[hv]), &cSlot))
	{
		do
		{
			if ((cSlot->key == k)) {
				dVal = cSlot->val;
				// 슬롯을 메모리에서 해제
				free(cSlot);
				LRemove(&(pt->tbl[hv]));
				return dVal;
			}
		} while (LNext(&(pt->tbl[hv]), &cSlot));
	}

	// 해당 key값이 존재하지 않을 경우 NULL 반환
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