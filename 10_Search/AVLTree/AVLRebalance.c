#include "AVLRebalance.h"
#include "BinaryTree.h"
#include <stdio.h>

// Ʈ���� ���̸� ����Ͽ� ��ȯ
int GetHeight(BTreeNode * bst)
{
	int leftH;	//left height
	int rightH;	//right height

	if (bst == NULL)
		return 0;

	leftH = GetHeight(GetLeftSubTree(bst));		// ���� ���� Ʈ�� ���� ���
	rightH = GetHeight(GetRightSubTree(bst));	// ������ ���� Ʈ�� ���� ���

	// ū ���� ���̸� ��ȯ�Ѵ�.
	if (leftH > rightH)
		return leftH + 1;

	else
		return rightH + 1;
}

// �� ���� Ʈ���� '������ ��(���� �μ�)'�� ��ȯ
int GetHeightDiff(BTreeNode * bst)
{
	int lsh;	// left sub tree height
	int rsh;	// right sub tree height

	if (bst == NULL)
		return 0;

	lsh = GetHeight(GetLeftSubTree(bst));	// ���� ���� Ʈ���� ����
	rsh = GetHeight(GetRightSubTree(bst));	// ������ ���� Ʈ���� ����

	return lsh - rsh;	// ���� �μ� ��� ��� ��ȯ
}
// LL ȸ���� ����ϴ� �Լ�
BTreeNode * RotateLL(BTreeNode * bst)
{
	BTreeNode * pNode;		// parent node
	BTreeNode * cNode;		// child node

	// pNode�� cNode�� LLȸ���� ���� ������ ��ġ�� ����Ű�� �Ѵ�.
	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	// ���� LLȸ���� ����ϴ� �� ���� ����
	ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
	ChangeRightSubTree(cNode, pNode);

	// LLȸ������ ���ؼ� ����� ��Ʈ ����� �ּ� �� ��ȯ
	return cNode;
}

// RR ȸ���� ����ϴ� �Լ�
BTreeNode * RotateRR(BTreeNode * bst)
{
	BTreeNode * pNode;	// parent node
	BTreeNode * cNode;	// child node

	// pNode�� cNode�� RRȸ���� ���� ������ ��ġ�� ����Ű�� �Ѵ�.
	pNode = bst;
	cNode = GetRightSubTree(bst);

	// ���� RRȸ���� ����ϴ� �� ���� ����
	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree(cNode, pNode);

	// RRȸ������ ���ؼ� ����� ��Ʈ ����� �ּ� �� ��ȯ
	return cNode;
}

// LR ȸ���� ����ϴ� �Լ�
BTreeNode * RotateLR(BTreeNode * bst)
{
	BTreeNode * pNode;	// parent node
	BTreeNode * cNode;	// child node

	// pNode�� cNode�� LRȸ���� ���� ������ ��ġ�� ����Ű�� �Ѵ�.
	pNode = bst;
	cNode = GetLeftSubTree(bst);

	// ���� LR ȸ���� ����ϴ� �� ���� ����
	ChangeLeftSubTree(pNode, RotateRR(cNode));	// �κ��� RRȸ�� �� pNode�� left sub node�� RRȸ���� ��Ʈ ���� ���� (LL���·� ������)
	return RotateLL(bst);						// LL ȸ��, ȸ������ ���� ����� ��Ʈ ����� �ּ� �� ��ȯ
}

// RL ȸ���� ����ϴ� �Լ�
BTreeNode * RotateRL(BTreeNode * bst)
{
	BTreeNode * pNode;	// parent node
	BTreeNode * cNode;	// child node

	// pNode�� cNode�� RLȸ���� ���� ������ ��ġ�� ����Ű�� �Ѵ�.
	pNode = bst;
	cNode = GetRightSubTree(bst);

	// ���� RL ȸ���� ����ϴ� �� ���� ����
	ChangeRightSubTree(pNode, RotateLL(cNode));	// �κ��� LLȸ�� �� pNode�� right sub node�� LLȸ���� ��Ʈ ���� ���� (LL���·� ������)
	return RotateRR(bst);						// RR ȸ��, ȸ������ ���� ����� ��Ʈ ����� �ּ� �� ��ȯ
}

BTreeNode * Rebalance(BTreeNode ** pRoot)
{
	int hDiff = GetHeightDiff(*pRoot);	// ���� �μ� ���

	// ���� �μ��� +2 �̻��̸� LL���� �Ǵ� LR �����̴�.
	if (hDiff > 1)	// ���� ���� Ʈ�� �������� ���̰� 2 �̻� ũ�ٸ�,
	{
		// ���� �ڽ� ��尡 +1 �̻��̸� LL ����
		if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
			*pRoot = RotateLL(*pRoot);
		else
			// ���� �ڽĳ�尡 -1 �����̸� LR ����
			*pRoot = RotateLR(*pRoot);
	}

	// ���� �μ��� -2 �����̸� RR���� �Ǵ� RL ����
	if (hDiff < -1)	// ������ ���� Ʈ�� �������� ���̰� 2�̻� ũ�ٸ�,
	{
		// ������ �ڽ� ��尡 -1 �����̸� RR ����
		if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
			*pRoot = RotateRR(*pRoot);
		else
			// ������ �ڽ� ��尡 +1 �̻��̸� RL ����
			*pRoot = RotateRL(*pRoot);
	}

	// Rebalance �� ����� ��ȯ
	return *pRoot;
}