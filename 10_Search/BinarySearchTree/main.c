#include <stdio.h>
#include "BinarySearchTree.h"

int main(void)
{
	BTreeNode * bstRoot;	// bstRoot는 BST의 루트 노드를 가리킨다.
	BTreeNode * sNode;		// 탐색결과를 반환 받을 노드

	BSTMakeAndInit(&bstRoot);	// Binary Search  Tree의 생성 및 초기화

	BSTInsert(&bstRoot, 9);		// bstRoot에 9를 저장
	BSTInsert(&bstRoot, 1);		// bstRoot에 1을 저장
	BSTInsert(&bstRoot, 6);		// bstRoot에 6을 저장
	BSTInsert(&bstRoot, 2);		// bstRoot에 2를 저장
	BSTInsert(&bstRoot, 8);		// bstRoot에 8을 저장
	BSTInsert(&bstRoot, 3);		// bstRoot에 3을 저장
	BSTInsert(&bstRoot, 5);		// bstRoot에 5를 저장

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