#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue * pq)
{
    pq->front = 0;
    pq->rear = 0;
}
int QIsEmpty(Queue * pq)
{
    return pq->front == pq->rear;
}

void Enqueue(Queue * pq, Data data)
{
    if ((pq->rear + 1) % QUE_LEN == pq->front)  // ť�� ���� ���
    {
        printf("Queue Memory Error!");
        exit(-1);
    }

    pq->rear = (pq->rear + 1) % QUE_LEN;    // rear�� �� ĭ �̵�
    pq->queArr[pq->rear] = data;            // rear�� ����Ű�� ���� ������ ����
}
Data Dequeue(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }
    pq->front = (pq->front + 1) % QUE_LEN;  // front�� �� ĭ �̵�
    return pq->queArr[pq->front];           // front�� ����Ű�� ������ ��ȯ
}
Data QPeek(Queue * pq)
{
    if (QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }
    return pq->queArr[(pq->front + 1) % QUE_LEN];           // front�� ����Ű�� ������ ��ȯ
}