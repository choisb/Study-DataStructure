#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _btreeNode
{
	BTData data;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
}BTreeNode;

// ���� Ʈ�� ��带 �����Ͽ� �� �ּ� ���� ��ȯ�Ѵ�.
BTreeNode * MakeBTreeNode(void);
// ��忡 ����� �����͸� ��ȯ�Ѵ�.
BTData GetData(BTreeNode * bt);

// ��忡 �����͸� �����Ѵ�. data�� ���޵� ���� �����Ѵ�.
void SetData(BTreeNode* bt, BTData data);

// ���� ���� Ʈ���� �ּ� ���� ��ȯ�Ѵ�.
BTreeNode * GetLeftSubTree(BTreeNode * bt);
// ������  ���� Ʈ���� �ּ� ���� ��ȯ�Ѵ�.
BTreeNode * GetRightSubTree(BTreeNode * bt);

// ���� ���� Ʈ���� �����Ѵ�. ���� ���� ���꿡 �����ϴ� Ʈ���� �޸� ����
void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);
// ������ ���� Ʈ���� �����Ѵ�. ���� ������ ���꿡 �����ϴ� Ʈ���� �޸� ���� 
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub);

// �޸��� �Ҹ��� �������� �ʰ� ���� �ڽ� ��带 ����
void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub);
// �޸��� �Ҹ��� �������� �ʰ� ������ �ڽ� ��带 ����
void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub);

// ���� �ڽ� ��� ����, ���ŵ� ����� �ּ� ���� ��ȯ (�޸� ����x)
BTreeNode * RemoveLeftSubTree(BTreeNode * bt);
// ������ �ڽ� ��� ����, ���ŵ� ����� �ּ� ���� ��ȯ (�޸� ����x)
BTreeNode * RemoveRightSubTree(BTreeNode * bt);

// ��� �湮�� �� ���� ������ ���� �� �ֵ��� �Ѵ�.
typedef void(*VisitFuncPtr)(BTData data);

// Ʈ���� ���ؼ� ���� ��ȸ�� Ž��
void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action);
// Ʈ���� ���ؼ� ���� ��ȸ�� Ž��
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action);
// Ʈ���� ���ؼ� ���� ��ȸ�� Ž��
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action);

// Ʈ���� ���� ���� �Ҹ�
void DeleteTree(BTreeNode * bt);

#endif