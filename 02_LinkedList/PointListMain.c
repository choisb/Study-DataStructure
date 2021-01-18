#include <stdio.h>
#include "DLinkedList.h"
#include "Point.h"

int WhoIsPrecede(Point* d1, Point* d2)
{
    if (d1->xpos < d2->xpos)  // x��ǥ �������� ��������.
        return 0;   
    else
        return 1;   
}

int main()
{
    List list;
    Point comPos;
    Point * ppos;

    ListInit(&list);

    SetSortRule(&list, WhoIsPrecede);

    // 7���� ������ ���� ////
    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 0);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 1, 2);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 3);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 1, 1);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 0, 0);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);
    LInsert(&list, ppos);

    // ����� �������� ��� ////
    printf("���� �������� ��: %d \n", LCount(&list));

    if (LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);
        while (LNext(&list, &ppos))
        {
            ShowPointPos(ppos);
        }
        printf("\n");
    }

    // xpos �� 2�� ��� ������ ���� ////
    comPos.xpos = 2;
    comPos.ypos = 0;

    if (LFirst(&list, &ppos))
    {
        if (PointComp(ppos, &comPos) == 0 || PointComp(ppos, &comPos) == 1)
        {
            ppos = LRemove(&list);
            free(ppos);
        }

        while (LNext(&list, &ppos))
        {
            if (PointComp(ppos, &comPos) == 0 || PointComp(ppos, &comPos) == 1)
            {
                ppos = LRemove(&list);
                free(ppos);
            }
        }
    }

    // ���� �� ���� ������ ��ü ��� ////
    printf("���� �������� ��: %d \n", LCount(&list));

    if (LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);
        while (LNext(&list, &ppos))
        {
            ShowPointPos(ppos);
        }
        printf("\n");
    }
}