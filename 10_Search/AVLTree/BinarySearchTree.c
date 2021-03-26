#include "BinarySearchTree.h"
#include "AVLRebalance.h"
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
	// ��� ���԰����� ����������� ȣ��
	if (*pRoot == NULL)
	{
		*pRoot = MakeBTreeNode();
		SetData(*pRoot, data);
	}
	else if (data < GetData(*pRoot))
	{
		BSTInsert(&((*pRoot)->left), data);
		// ���Ե� ����� ��� �θ��忡 ���� Rebalnce ����
		*pRoot = Rebalance(pRoot);
	}
	else if (data > GetData(*pRoot))
	{
		BSTInsert(&((*pRoot)->right), data);
		// ���Ե� ����� ��� �θ��忡 ���� Rebalnce ����
		*pRoot = Rebalance(pRoot);
	}
	else
	{
		return NULL; // Ű�� �ߺ��� ������� �ʴ´�.
	}
	return *pRoot;
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
	BTreeNode * cNode = bst;	// current node
	BSTData cd;					// current data

	while (cNode != NULL)
	{
		cd = GetData(cNode);

		// Ž�� ��� �߰�
		if (target == cd)
			return cNode;	
		else if (target < cd)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	return NULL;	// Ž������� ����Ǿ� ���� ����.
}

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)
{
	// ���� ����� ��Ʈ ����� ��츦 ������ ����ؾ� �Ѵ�.
	// ���� �����带 �δ� ������ 
	// ������ ��尡 ��Ʈ ����� ����� �������� ���� �帧�� �Ϲ�ȭ �ϱ� ����.
	// ���� ���ؼ� ��Ʈ ��带 ���� ����� �ڽĳ��� �������� ���ؼ�
	// ��� ��尡(��Ʈ��� ����) ������ ����� ���� ������ ������ �ϵ��� �ϱ� ����.

	BTreeNode * pVRoot = MakeBTreeNode();	// ���� ��Ʈ ���
	BTreeNode * pNode = pVRoot;				// parent node
	BTreeNode * cNode = *pRoot;				// current node
	BTreeNode * dNode;						// delete node

	// ��Ʈ ��带 pVRoot�� ����Ű�� ����� ������ �ڽ� ��尡 �ǰ� �Ѵ�.
	ChangeRightSubTree(pVRoot, *pRoot);

	// ���� ����� ��带 Ž��
	// ��� Ž���� ���� BSTSearch()�Լ��� ������� ���� ������
	// cNode�� target�� ����Ű���� Ž���ϴ� �� �Ӹ� �ƴ϶�
	// cNode�� �θ��� pNode�� target�� �θ��带 ����Ű�� �ϱ� �����̴�.
	while (cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;
		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	if (cNode == NULL)	// ���� ����� �������� �ʴ´ٸ�,
		return NULL;

	dNode = cNode;

	// ù ��° ���: ���� ����� �ܸ� ����� ���
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}

	// �� ��° ���: ���� ����� �ϳ��� �ڽ� ��带 ���� ���
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode * dcNode;		//���� ����� �ڽ� ��� ����Ŵ

		// ���� ����� ���ʿ� �ڽ� ��带 ������ �ִ� ���
		if (GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);

		// ���� ����� �����ʿ� �ڽ� ��带 ������ �ִ� ���
		else
			dcNode = GetRightSubTree(dNode);

		// ���� ����� �θ����� ���ʿ� �ִ� ���
		if (GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}

	// �� ��° ���: �� ���� �ڽ� ��带 ��� ���� ���
	else
	{
		BTreeNode * mNode = GetRightSubTree(dNode);	// ��ü ��� ����Ŵ
		BTreeNode * mpNode = dNode;					// ��ü ����� �θ� ��� ����Ŵ
		BTData delData;

		// ���� ����� ��ü ��带 ã�´�.
		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		// ��ü ��忡 ����� ���� ������ ��忡 �����Ѵ�.
		delData = GetData(dNode);		// ���� �� ������ ���
		SetData(dNode, GetData(mNode));	// ����

		// ��ü ����� �θ� ���� �ڽ� ��带 �����Ѵ�.
		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData);	// ��� ������ ����
	}

	// ������ ��尡 ��Ʈ ����� ��쿡 ���� �߰����� ó��
	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);	// ��Ʈ ����� ������ �ݿ�

	free(pVRoot);	// ���� ��Ʈ ����� �Ҹ�
	
	// ��� ���� �� ���뷱��
	*pRoot = Rebalance(pRoot);

	// ������ ����� �����Ͱ� ����ִ� ����� �ּҰ� ��ȯ.
	return dNode;

}

void ShowIntData(int data)
{
	printf("%d ", data);
}
void BSTShowAll(BTreeNode * bst)
{
	InorderTraverse(bst, ShowIntData);	// ���� ��ȸ
}