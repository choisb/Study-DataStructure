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
// 이진 트리 노드를 생성하여 그 주소 값을 반환한다.
BTData GetData(BTreeNode * bt);
// 노드에 저장된 데이터를 반환한다.

void SetData(BTreeNode* bt, BTData data);
// 노드에 데이터를 저장한다. data로 전달된 값을 전달한다.

BTreeNode * GetLeftSubTree(BTreeNode * bt);
// 왼쪽 서브 트리의 주소 값을 반환한다.
BTreeNode * GetRightSubTree(BTreeNode * bt);
// 오른쪽  서브 트리의 주소 값을 반환한다.

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub); 
// 왼쪽 서브 트리를 연결한다.
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub);
// 오른쪽 서브 트리를 연결한다.

typedef void (*VisitFuncPtr)(BTData data);
// 노드 방문시 할 일을 유저가 정할 수 있도록 한다.

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action);
// 트리에 대해서 전위 순회로 탐색
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action);
// 트리에 대해서 중위 순회로 탐색
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action);
// 트리에 대해서 후위 순회로 탐색

void DeleteTree(BTreeNode * bt);
// 트리에 대한 완전 소멸


#endif