#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2)
{
    if (d1 < d2)
        return 0;   // d1이 정렬 순서상 앞선다.
    else
        return 1;   // d2가 정렬 순서상 앞선다.
}

int main()
{
    // DLinked List의 생성 및 초기화 ////
    List list;
    int data;
    ListInit(&list);

    SetSortRule(&list, WhoIsPrecede);  //정렬기준 함수 등록


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

    // 저장된 데이터의 전체 합산 ////
    printf("현재 데이터의 수: %d \n", LCount(&list));

    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        while (LNext(&list, &data)) {
            printf("%d ", data);

        }
        printf("\n\n");
    }

    // 2의 배수, 3의 배수 삭제 ////
    if (LFirst(&list, &data))
    {
        printf("2의 배수, 3의 배수 삭제\n");
        if ((data % 2 == 0) || (data % 3 == 0))
            LRemove(&list);

        while (LNext(&list, &data))
        {
            if ((data % 2 == 0) || (data % 3 == 0))
                LRemove(&list);
        }
    }

    // 삭제 후 남은 데이터 전체 출력 ////
    printf("현재 데이터의 수: %d \n", LCount(&list));

    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        while (LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");
    return 0;
}