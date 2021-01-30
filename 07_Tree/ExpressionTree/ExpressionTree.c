#include "ExpressionTree.h"
#include "ListBaseStack.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
// 후위표기법 수식을 매개변수로 받고 트리로 만듦
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

        // 숫자일 경우 무조건 스택에 push
        if (isdigit(tok))
        {
            SetData(pnode, tok - '0');           
        }

        // 연산자일 경우 스택에서 2개를 깨내어 트리로 만든 후 push
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

// 수식트리를 매개변수로 받고 계산 결과를 반환
int EvaluateExpTree(BTreeNode * bt)
{
    int op1, op2;

    // 단말노드라면 현재 데이터를 반환
    if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
        return GetData(bt);

    // 단말노드가 아니라면 연산진행
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
// 노드 순회시 행동할 함수.
void ShowNodeData(int data)
{
    if (0 <= data && data <= 9)
        printf("%d ", data); // 피연산자 출력
    else
        printf("%c ", data); // 연산자 출력
}

// 수식트리의 구성을 검증하기 위한 함수.
void ShowPrefixTypeExp(BTreeNode * bt) // 전위 표기법 기반 출력
{
    // 전위 표기법으로 출력하기 위해서는 전위 순회하면서 출력
    PreorderTraverse(bt, ShowNodeData);
}
void ShowInfixTypeExp(BTreeNode * bt)  // 중위 표기법 기반 출력
{
    // 중위 표기법으로 출력하기 위해서는 중위 순회하면서 출력
    InorderTraverse(bt, ShowNodeData);
}
void ShowPostfixTypeExp(BTreeNode * bt)// 후위 표기법 기반 출력
{
    // 후위 표기법으로 출력하기 위해서는 후위 순회하면서 출력
    PostorderTraverse(bt, ShowNodeData);
}

