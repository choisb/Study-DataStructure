#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__


#include "BinaryTree.h"

// ����ǥ��� ������ �Ű������� �ް� Ʈ���� ����
BTreeNode * MakeExpTree(char exp[]);    // ���� Ʈ�� ����

// ����Ʈ���� �Ű������� �ް� ��� ����� ��ȯ
int EvaluateExpTree(BTreeNode * bt);    // ���� Ʈ�� ���

// ����Ʈ���� ������ �����ϱ� ���� �Լ�.
void ShowPrefixTypeExp(BTreeNode * bt); // ���� ǥ��� ��� ���
void ShowInfixTypeExp(BTreeNode * bt);  // ���� ǥ��� ��� ���
void ShowPostfixTypeExp(BTreeNode * bt);// ���� ǥ��� ��� ���

#endif // !__EXPRESSION_TREE_H__
