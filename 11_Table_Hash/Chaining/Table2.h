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

// 테이블의 초기화, 사용자로 부터 해시함수를 등록받는다
void TBLInit(Table * pt, HashFunc * f);

// 테이블에 키와 값을 저장
void TBLInsert(Table * pt, Key k, Value v);

// 키를 근거로 테이블에서 데이터 삭제
Value TBLDelete(Table * pt, Key k);

// 키를 근거로 테이블에서 데이터 탐색
Value TBLSearch(Table * pt, Key k);

#endif