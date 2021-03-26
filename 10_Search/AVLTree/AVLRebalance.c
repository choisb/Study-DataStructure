#include "AVLRebalance.h"
#include "BinaryTree.h"
#include <stdio.h>

// 트리의 높이를 계산하여 반환
int GetHeight(BTreeNode * bst)
{
	int leftH;	//left height
	int rightH;	//right height

	if (bst == NULL)
		return 0;

	leftH = GetHeight(GetLeftSubTree(bst));		// 왼쪽 서브 트리 높이 계산
	rightH = GetHeight(GetRightSubTree(bst));	// 오른쪽 서브 트리 높이 계산

	// 큰 값의 높이를 반환한다.
	if (leftH > rightH)
		return leftH + 1;

	else
		return rightH + 1;
}

// 두 서브 트리의 '높이의 차(균형 인수)'를 반환
int GetHeightDiff(BTreeNode * bst)
{
	int lsh;	// left sub tree height
	int rsh;	// right sub tree height

	if (bst == NULL)
		return 0;

	lsh = GetHeight(GetLeftSubTree(bst));	// 왼쪽 서브 트리의 높이
	rsh = GetHeight(GetRightSubTree(bst));	// 오른쪽 서브 트리의 높이

	return lsh - rsh;	// 균형 인수 계산 결과 반환
}
// LL 회전을 담당하는 함수
BTreeNode * RotateLL(BTreeNode * bst)
{
	BTreeNode * pNode;		// parent node
	BTreeNode * cNode;		// child node

	// pNode와 cNode가 LL회전을 위해 적절한 위치를 가리키게 한다.
	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	// 실제 LL회전을 담당하는 두 개의 문장
	ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
	ChangeRightSubTree(cNode, pNode);

	// LL회전으로 인해서 변경된 루트 노드의 주소 값 반환
	return cNode;
}

// RR 회전을 담당하는 함수
BTreeNode * RotateRR(BTreeNode * bst)
{
	BTreeNode * pNode;	// parent node
	BTreeNode * cNode;	// child node

	// pNode와 cNode가 RR회전을 위해 적절한 위치를 가리키게 한다.
	pNode = bst;
	cNode = GetRightSubTree(bst);

	// 실제 RR회전을 담당하는 두 개의 문장
	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree(cNode, pNode);

	// RR회전으로 인해서 변경된 루트 노드의 주소 값 반환
	return cNode;
}

// LR 회전을 담당하는 함수
BTreeNode * RotateLR(BTreeNode * bst)
{
	BTreeNode * pNode;	// parent node
	BTreeNode * cNode;	// child node

	// pNode와 cNode가 LR회전을 위해 적절한 위치를 가리키게 한다.
	pNode = bst;
	cNode = GetLeftSubTree(bst);

	// 실제 LR 회전을 담당하는 두 개의 문장
	ChangeLeftSubTree(pNode, RotateRR(cNode));	// 부분적 RR회전 후 pNode의 left sub node를 RR회전한 루트 노드로 변경 (LL형태로 구성됨)
	return RotateLL(bst);						// LL 회전, 회전으로 인해 변경된 루트 노드의 주소 값 반환
}

// RL 회전을 담당하는 함수
BTreeNode * RotateRL(BTreeNode * bst)
{
	BTreeNode * pNode;	// parent node
	BTreeNode * cNode;	// child node

	// pNode와 cNode가 RL회전을 위해 적절한 위치를 가리키게 한다.
	pNode = bst;
	cNode = GetRightSubTree(bst);

	// 실제 RL 회전을 담당하는 두 개의 문장
	ChangeRightSubTree(pNode, RotateLL(cNode));	// 부분적 LL회전 후 pNode의 right sub node를 LL회전한 루트 노드로 변경 (LL형태로 구성됨)
	return RotateRR(bst);						// RR 회전, 회전으로 인해 변경된 루트 노드의 주소 값 반환
}

BTreeNode * Rebalance(BTreeNode ** pRoot)
{
	int hDiff = GetHeightDiff(*pRoot);	// 균형 인수 계산

	// 균형 인수가 +2 이상이면 LL상태 또는 LR 상태이다.
	if (hDiff > 1)	// 왼쪽 서브 트리 방향으로 높이가 2 이상 크다면,
	{
		// 왼쪽 자식 노드가 +1 이상이면 LL 상태
		if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
			*pRoot = RotateLL(*pRoot);
		else
			// 왼쪽 자식노드가 -1 이하이면 LR 상태
			*pRoot = RotateLR(*pRoot);
	}

	// 균형 인수가 -2 이하이면 RR상태 또는 RL 상태
	if (hDiff < -1)	// 오른쪽 서브 트리 방향으로 높이가 2이상 크다면,
	{
		// 오른쪽 자식 노드가 -1 이하이면 RR 상태
		if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
			*pRoot = RotateRR(*pRoot);
		else
			// 오른쪽 자식 노드가 +1 이상이면 RL 상태
			*pRoot = RotateRL(*pRoot);
	}

	// Rebalance 된 결과를 반환
	return *pRoot;
}