#include <stdio.h>
#include "DLinkedList.h"
#include "Point.h"

int WhoIsPrecede(Point* d1, Point* d2)
{
    if (d1->xpos < d2->xpos)  // x좌표 기준으로 오름차순.
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

    // 7개의 데이터 저장 ////
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

    // 저장된 데이터의 출력 ////
    printf("현재 데이터의 수: %d \n", LCount(&list));

    if (LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);
        while (LNext(&list, &ppos))
        {
            ShowPointPos(ppos);
        }
        printf("\n");
    }

    // xpos 가 2인 모든 데이터 삭제 ////
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

    // 삭제 후 남은 데이터 전체 출력 ////
    printf("현재 데이터의 수: %d \n", LCount(&list));

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