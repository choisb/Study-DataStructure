#include <stdio.h>
#include "DBDLinkedList.h"

int main()
{
    // 리스트 생성 및 초기화 ////
    List list;
    LData data;
    ListInit(&list);

    // 8개의 데이터 저장 ////
    LInsert(&list, 5);
    LInsert(&list, 1);
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 6);
    LInsert(&list, 7);
    LInsert(&list, 8);

    // 저장된 데이터 조회 ////
    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        // 오른쪽 노드로 이동하며 데이터 조회
        while (LNext(&list, &data))
            printf("%d ", data);

        printf("\n\n");

        while (LPrevious(&list, &data))
            printf("%d ", data);

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

    // 저장된 데이터 조회 ////
    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        // 오른쪽 노드로 이동하며 데이터 조회
        while (LNext(&list, &data))
            printf("%d ", data);

        printf("\n\n");

        while (LPrevious(&list, &data))
            printf("%d ", data);

        printf("\n\n");
    }
    return 0;
}