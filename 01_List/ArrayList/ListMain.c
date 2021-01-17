#include <stdio.h>
#include "ArrayList.h"

int main()
{
    // ArrayList�� ���� �� �ʱ�ȭ ////
    List list;
    int data, i;
    int sum = 0;
    ListInit(&list);

    // 0~9 ������ ���� ������ ���� ////
    for (i = 0; i < 10; i++)
        LInsert(&list, i);

    // ����� �������� ��ü �ջ� ////
    printf("���� �������� ��: %d \n", LCount(&list));

    if (LFirst(&list, &data))
    {
        sum += data;

        while (LNext(&list, &data)) 
            sum += data;
    }
    printf("sum: %d\n\n", sum);

    // 2�� ���, 3�� ��� ���� ////
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