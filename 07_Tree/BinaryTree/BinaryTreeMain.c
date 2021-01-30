#include <stdio.h>
#include "BinaryTree.h"

void ShowIntData(int data);

int main()
{
    BTreeNode * bt1 = MakeBTreeNode();  // ��� bt1 ����
    BTreeNode * bt2 = MakeBTreeNode();  // ��� bt2 ����
    BTreeNode * bt3 = MakeBTreeNode();  // ��� bt3 ����
    BTreeNode * bt4 = MakeBTreeNode();  // ��� bt4 ����
    BTreeNode * bt5 = MakeBTreeNode();  // ��� bt5 ����
    BTreeNode * bt6 = MakeBTreeNode();  // ��� bt6 ����

    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);
    SetData(bt5, 5);
    SetData(bt6, 6);

    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt2, bt4);
    MakeRightSubTree(bt2, bt5);
    MakeRightSubTree(bt3, bt6);

    PreorderTraverse(bt1, ShowIntData);
    printf("\n");

    InorderTraverse(bt1, ShowIntData);
    printf("\n");

    PostorderTraverse(bt1, ShowIntData);
    printf("\n");

    DeleteTree(bt1);

    return 0;
}
void ShowIntData(int data)
{
    printf("%d ", data);
}