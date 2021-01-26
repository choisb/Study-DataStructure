#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode * MakeBTreeNode(void)
{
    BTreeNode * newNode;
    newNode = (BTreeNode*)malloc(sizeof(BTreeNode));

    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
BTData GetData(BTreeNode * bt)
{
    return bt->data;
}
void SetData(BTreeNode* bt, BTData data)
{
    bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt)
{
    return bt->left;
}
BTreeNode * GetRightSubTree(BTreeNode * bt)
{
    return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
    // left 에 트리가 존재할 경우 전부 삭제하는 코드 필요.
    main->left = sub;
}
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
    // right 에 트기가 존재할 경우 전부 삭제하는 코드 필요.
    main->right = sub;
}
typedef void(*VisitFuncPtr)(BTData data);

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;

    action(bt->data);
    PreorderTraverse(bt->left, action);
    PreorderTraverse(bt->right, action);
}
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;

    InorderTraverse(bt->left, action);
    action(bt->data);
    InorderTraverse(bt->right, action);
}
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;

    PostorderTraverse(bt->left, action);
    PostorderTraverse(bt->right, action);
    action(bt->data);
}


void DeleteTree(BTreeNode * bt)
{
    if (bt == NULL)
        return;

    DeleteTree(bt->left);
    DeleteTree(bt->right);

    printf("del tree data: %d \n", bt->data);
    free(bt);
}