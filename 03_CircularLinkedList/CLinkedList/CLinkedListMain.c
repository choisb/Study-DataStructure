#include <stdio.h>
#include "CLinkedList.h"

int main()
{
    // DLinked List�� ���� �� �ʱ�ȭ ////
    List list;
    int data, i, nodeNum;
    ListInit(&list);

    // ����Ʈ �ڿ� �տ� ������ ���� ////
    LInsert(&list, 1);
    LInsert(&list, 7);
    LInsert(&list, 8);
    LInsertFront(&list, 3);
    LInsertFront(&list, 5);
    LInsertFront(&list, 2);
    LInsertFront(&list, 4);

    // ����Ʈ�� ����� �����͸� ���� 3ȸ ��� ////

    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        for (i = 0; i < LCount(&list) * 3 - 1; i++)
        {
            if (LNext(&list, &data))
                printf("%d ", data);
        }
    }
    printf("\n\n");

    // 2�� ����� ã�Ƽ� ��� ���� ////
    nodeNum = LCount(&list);

    if (nodeNum != 0)
    {
        LFirst(&list, &data);
        if (data % 2 == 0)
            LRemove(&list);

        for (i = 0; i < nodeNum - 1; i++)
        {
            LNext(&list, &data);
            if (data % 2 == 0)
                LRemove(&list);
        }
    }

    // ��ü ������ 1ȸ  ��� /////
    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        for (i = 0; i < LCount(&list) - 1; i++)
        {
            if (LNext(&list, &data))
                printf("%d ", data);
        }
    }

    return 0;
}