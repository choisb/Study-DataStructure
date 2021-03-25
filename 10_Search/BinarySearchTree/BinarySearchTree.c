#include "BinarySearchTree.h"
#include <stdio.h>
void BSTMakeAndInit(BTreeNode ** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
	return (BSTData) bst->data;
}

void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
	BTreeNode * pNode = NULL;	// parent node
	BTreeNode * cNode = *pRoot;	// current node
	BTreeNode * nNode = NULL;	// new node

	while (cNode != NULL)
	{
		if (data == GetData(cNode))
			return;	// 데이터의(키의) 중복을 허용하지 않음

		pNode = cNode;

		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	// pNode의 자식 노드로 추가할 새 노드의 생성
	nNode = MakeBTreeNode();	// 새 노드의 생성
	SetData(nNode, data);		// 새 노드에 데이터 저장

	// pNode의 자식 노드로 새 노드를 추가
	if (pNode != NULL) // 새 노드가 루트 노드가 아니라면,
	{
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else // 새노드가 루트 노르가면
	{
		*pRoot = nNode;
	}
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
	BTreeNode * cNode = bst;	// current node
	BSTData cd;					// current data

	while (cNode != NULL)
	{
		cd = GetData(cNode);

		// 탐색 대상 발견
		if (target == cd)
			return cNode;	
		else if (target < cd)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	return NULL;	// 탐색대상이 저장되어 있지 않음.
}

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)
{
	// 삭제 대상이 루트 노드인 경우를 별도로 고려해야 한다.
	// 굳이 가상노드를 두는 이유는 
	// 삭제할 노드가 루트 노드인 경우의 예외적인 삭제 흐름을 일반화 하기 위함.
	// 쉽게 말해서 루트 노드를 가상 노드의 자식노드로 만듦으로 인해서
	// 모든 노드가(루트노드 포함) 동일한 방식의 삭제 절차를 따르게 하도록 하기 위함.

	BTreeNode * pVRoot = MakeBTreeNode();	// 가상 루트 노드
	BTreeNode * pNode = pVRoot;				// parent node
	BTreeNode * cNode = *pRoot;				// current node
	BTreeNode * dNode;						// delete node

	// 루트 노드를 pVRoot가 가리키는 노드의 오른쪽 자식 노드가 되게 한다.
	ChangeRightSubTree(pVRoot, *pRoot);

	// 삭제 대상인 노드를 탐색
	// 노드 탐색을 위한 BSTSearch()함수를 사용하지 않은 이유는
	// cNode가 target을 가리키도록 탐색하는 것 뿐만 아니라
	// cNode의 부모인 pNode가 target의 부모노드를 가리키게 하기 위함이다.
	while (cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;
		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	if (cNode == NULL)	// 삭제 대상이 존재하지 않는다면,
		return NULL;

	dNode = cNode;

	// 첫 번째 경우: 삭제 대상이 단말 노드인 경우
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}

	// 두 번째 경우: 삭제 대상이 하나의 자식 노드를 갖는 경우
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode * dcNode;		//삭제 대상의 자식 노드 가리킴

		// 삭제 대상이 왼쪽에 자식 노드를 가지고 있는 경우
		if (GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);

		// 삭제 대상이 오른쪽에 자식 노드를 가지고 있는 경우
		else
			dcNode = GetRightSubTree(dNode);

		// 삭제 대상이 부모노드의 왼쪽에 있는 경우
		if (GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}

	// 세 번째 경우: 두 개의 자식 노드를 모두 갖는 경우
	else
	{
		BTreeNode * mNode = GetRightSubTree(dNode);	// 대체 노드 가리킴
		BTreeNode * mpNode = dNode;					// 대체 노드의 부모 노드 가리킴
		BTData delData;

		// 삭제 대상의 대체 노드를 찾는다.
		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		// 대체 노드에 저장된 값을 삭제할 노드에 대입한다.
		delData = GetData(dNode);		// 대입 전 데이터 백업
		SetData(dNode, GetData(mNode));	// 대입

		// 대체 노드의 부모 노드와 자식 노드를 연결한다.
		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData);	// 백업 데이터 복원
	}

	// 삭제된 노드가 루트 노드인 경우에 대한 추가적인 처리
	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);	// 루트 노드의 변경을 반영

	free(pVRoot);	// 가상 루트 노드의 소멸

	// 삭제할 노드의 데이터가 들어있는 노드의 주소값 반환.
	return dNode;

}

void ShowIntData(int data)
{
	printf("%d ", data);
}
void BSTShowAll(BTreeNode * bst)
{
	InorderTraverse(bst, ShowIntData);	// 중위 순회
}