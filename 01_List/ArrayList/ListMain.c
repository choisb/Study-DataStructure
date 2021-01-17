#include <stdio.h>
#include "ArrayList.h"

int main()
{
    // ArrayList의 생성 및 초기화 ////
    List list;
    int data, i;
    int sum = 0;
    ListInit(&list);

    // 0~9 까지의 정수 데이터 저장 ////
    for (i = 0; i < 10; i++)
        LInsert(&list, i);

    // 저장된 데이터의 전체 합산 ////
    printf("현재 데이터의 수: %d \n", LCount(&list));

    if (LFirst(&list, &data))
    {
        sum += data;

        while (LNext(&list, &data)) 
            sum += data;
    }
    printf("sum: %d\n\n", sum);

    // 2의 배수, 3의 배수 삭제 ////
    if (LFirst(&list, &data))
    {
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