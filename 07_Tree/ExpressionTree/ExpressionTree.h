#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__


#include "BinaryTree.h"

// 후위표기법 수식을 매개변수로 받고 트리로 만듦
BTreeNode * MakeExpTree(char exp[]);    // 수식 트리 구성

// 수식트리를 매개변수로 받고 계산 결과를 반환
int EvaluateExpTree(BTreeNode * bt);    // 수식 트리 계산

// 수식트리의 구성을 검증하기 위한 함수.
void ShowPrefixTypeExp(BTreeNode * bt); // 전위 표기법 기반 출력
void ShowInfixTypeExp(BTreeNode * bt);  // 중위 표기법 기반 출력
void ShowPostfixTypeExp(BTreeNode * bt);// 후위 표기법 기반 출력

#endif // !__EXPRESSION_TREE_H__
