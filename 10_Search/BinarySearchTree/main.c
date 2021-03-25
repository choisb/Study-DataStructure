#include <stdio.h>
#include "BinarySearchTree.h"

int main(void)
{
	BTreeNode * bstRoot;	// bstRoot�� BST�� ��Ʈ ��带 ����Ų��.
	BTreeNode * sNode;		// Ž������� ��ȯ ���� ���

	BSTMakeAndInit(&bstRoot);	// Binary Search  Tree�� ���� �� �ʱ�ȭ

	BSTInsert(&bstRoot, 9);		// bstRoot�� 9�� ����
	BSTInsert(&bstRoot, 1);		// bstRoot�� 1�� ����
	BSTInsert(&bstRoot, 6);		// bstRoot�� 6�� ����
	BSTInsert(&bstRoot, 2);		// bstRoot�� 2�� ����
	BSTInsert(&bstRoot, 8);		// bstRoot�� 8�� ����
	BSTInsert(&bstRoot, 3);		// bstRoot�� 3�� ����
	BSTInsert(&bstRoot, 5);		// bstRoot�� 5�� ����

	BSTShowAll(bstRoot);
	printf("\n");

	sNode = BSTRemove(&bstRoot, 3);
	free(sNode);
	BSTShowAll(bstRoot);
	printf("\n");

	sNode = BSTRemove(&bstRoot, 8);
	free(sNode);
	BSTShowAll(bstRoot);
	printf("\n");

	sNode = BSTRemove(&bstRoot, 1);
	free(sNode);
	BSTShowAll(bstRoot);
	printf("\n");

	sNode = BSTRemove(&bstRoot, 8);
	free(sNode);
	BSTShowAll(bstRoot);
	printf("\n");

	sNode = BSTRemove(&bstRoot, 6);
	free(sNode);
	BSTShowAll(bstRoot);
	printf("\n");

	return 0;
}