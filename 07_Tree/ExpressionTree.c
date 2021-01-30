#include "ExpressionTree.h"
#include "ListBaseStack.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
// ����ǥ��� ������ �Ű������� �ް� Ʈ���� ����
BTreeNode * MakeExpTree(char exp[])
{
    Stack stack;
    BTreeNode * pnode;
    int expLen, i = 0;
    char tok;

    expLen = strlen(exp);

    StackInit(&stack);

    for( i = 0; i < expLen; i++)
    {
        tok = exp[i];
        pnode = MakeBTreeNode();

        // ������ ��� ������ ���ÿ� push
        if (isdigit(tok))
        {
            SetData(pnode, tok - '0');           
        }

        // �������� ��� ���ÿ��� 2���� ������ Ʈ���� ���� �� push
        else
        {
            SetData(pnode, tok);
            MakeRightSubTree(pnode, SPop(&stack));
            MakeLeftSubTree(pnode, SPop(&stack));
        }

        SPush(&stack, pnode);
    }
    return SPop(&stack);
}

// ����Ʈ���� �Ű������� �ް� ��� ����� ��ȯ
int EvaluateExpTree(BTreeNode * bt)
{
    int op1, op2;

    // �ܸ������ ���� �����͸� ��ȯ
    if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
        return GetData(bt);

    // �ܸ���尡 �ƴ϶�� ��������
    op1 = EvaluateExpTree(GetLeftSubTree(bt));
    op2 = EvaluateExpTree(GetRightSubTree(bt));

    switch (GetData(bt))
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    }

    return 0;
}
// ��� ��ȸ�� �ൿ�� �Լ�.
void ShowNodeData(int data)
{
    if (0 <= data && data <= 9)
        printf("%d ", data); // �ǿ����� ���
    else
        printf("%c ", data); // ������ ���
}

// ����Ʈ���� ������ �����ϱ� ���� �Լ�.
void ShowPrefixTypeExp(BTreeNode * bt) // ���� ǥ��� ��� ���
{
    // ���� ǥ������� ����ϱ� ���ؼ��� ���� ��ȸ�ϸ鼭 ���
    PreorderTraverse(bt, ShowNodeData);
}
void ShowInfixTypeExp(BTreeNode * bt)  // ���� ǥ��� ��� ���
{
    // ���� ǥ������� ����ϱ� ���ؼ��� ���� ��ȸ�ϸ鼭 ���
    InorderTraverse(bt, ShowNodeData);
}
void ShowPostfixTypeExp(BTreeNode * bt)// ���� ǥ��� ��� ���
{
    // ���� ǥ������� ����ϱ� ���ؼ��� ���� ��ȸ�ϸ鼭 ���
    PostorderTraverse(bt, ShowNodeData);
}

