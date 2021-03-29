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
    if ((pq->rear + 1) % QUE_LEN == pq->front)  // 큐가 꽉찬 경우
    {
        printf("Queue Memory Error!");
        exit(-1);
    }

    pq->rear = (pq->rear + 1) % QUE_LEN;    // rear을 한 칸 이동
    pq->queArr[pq->rear] = data;            // rear이 가리키는 곳에 데이터 저장
}
Data Dequeue(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }
    pq->front = (pq->front + 1) % QUE_LEN;  // front를 한 칸 이동
    return pq->queArr[pq->front];           // front가 가리키는 데이터 반환
}
Data QPeek(Queue * pq)
{
    if (QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }
    return pq->queArr[(pq->front + 1) % QUE_LEN];           // front가 가리키는 데이터 반환
}