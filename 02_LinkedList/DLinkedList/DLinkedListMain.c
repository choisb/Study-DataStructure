#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2)
{
    if (d1 < d2)
        return 0;   // d1�� ���� ������ �ռ���.
    else
        return 1;   // d2�� ���� ������ �ռ���.
}

int main()
{
    // DLinked List�� ���� �� �ʱ�ȭ ////
    List list;
    int data;
    ListInit(&list);

    SetSortRule(&list, WhoIsPrecede);  //���ı��� �Լ� ���


    LInsert(&list, 1);
    LInsert(&list, 7);
    LInsert(&list, 8);
    LInsert(&list, 5);
    LInsert(&list, 6);
    LInsert(&list, 11);
    LInsert(&list, 17);
    LInsert(&list, 8);
    LInsert(&list, 6);
    LInsert(&list, 2);
    LInsert(&list, 6);
    LInsert(&list, 1);
    LInsert(&list, 3);

    // ����� �������� ��ü �ջ� ////
    printf("���� �������� ��: %d \n", LCount(&list));

    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        while (LNext(&list, &data)) {
            printf("%d ", data);

        }
        printf("\n\n");
    }

    // 2�� ���, 3�� ��� ���� ////
    if (LFirst(&list, &data))
    {
        printf("2�� ���, 3�� ��� ����\n");
        if ((data % 2 == 0) || (data % 3 == 0))
            LRemove(&list);

        while (LNext(&list, &data))
        {
            if ((data % 2 == 0) || (data % 3 == 0))
                LRemove(&list);
        }
    }

    // ���� �� ���� ������ ��ü ��� ////
    printf("���� �������� ��: %d \n", LCount(&list));

    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        while (LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");
    return 0;
}