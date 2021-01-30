#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _btreeNode
{
    BTData data;
    struct _bTreeNode * left;
    struct _bTreeNode * right;
}BTreeNode;

BTreeNode * MakeBTreeNode(void);
// ���� Ʈ�� ��带 �����Ͽ� �� �ּ� ���� ��ȯ�Ѵ�.
BTData GetData(BTreeNode * bt);
// ��忡 ����� �����͸� ��ȯ�Ѵ�.

void SetData(BTreeNode* bt, BTData data);
// ��忡 �����͸� �����Ѵ�. data�� ���޵� ���� �����Ѵ�.

BTreeNode * GetLeftSubTree(BTreeNode * bt);
// ���� ���� Ʈ���� �ּ� ���� ��ȯ�Ѵ�.
BTreeNode * GetRightSubTree(BTreeNode * bt);
// ������  ���� Ʈ���� �ּ� ���� ��ȯ�Ѵ�.

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub); 
// ���� ���� Ʈ���� �����Ѵ�.
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub);
// ������ ���� Ʈ���� �����Ѵ�.

typedef void (*VisitFuncPtr)(BTData data);
// ��� �湮�� �� ���� ������ ���� �� �ֵ��� �Ѵ�.

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action);
// Ʈ���� ���ؼ� ���� ��ȸ�� Ž��
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action);
// Ʈ���� ���ؼ� ���� ��ȸ�� Ž��
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action);
// Ʈ���� ���ؼ� ���� ��ȸ�� Ž��

void DeleteTree(BTreeNode * bt);
// Ʈ���� ���� ���� �Ҹ�


#endif