#include "ALGraphBFS.h"
#include "CircularQueue.h"
#include <stdio.h>
#include <stdlib.h>

int WhoIsPrecede(LData data1, LData data2)
{
	return data1 > data2;
}

void GraphInit(ALGraph * pg, int nv)
{
	int i;

	// 정점의 수에 해당하는 길이의 리스트 배열을 생성한다.
	pg->adjList = (List*)malloc(sizeof(List) * nv);	// 간선정보를 저장할 리스트 생성

	// 정점의 수만큼 생성된 리스트들을 초기화한다.
	for (i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}

	// 방문 정보를 저장하기 위해서 정점의 수와 같은 크기의 배열을 할당하고 초기화
	pg->queueInfo = (int*)malloc(sizeof(int) * nv);
	memset(pg->queueInfo, 0, sizeof(int) * nv);

	// 정점의 수와 간선의 수 초기화
	pg->numV = nv;	// 정점의 수는 nv에 저장된 값으로 결정
	pg->numE = 0;	// 초기의 간선 수는 0개
}

void GraphDestroy(ALGraph * pg)
{
	int i;
	int vx;

	if (pg->adjList != NULL)
	{
		for (i = 0; i < pg->numV; i++)
		{
			// 리스트에 저장된 노드가 없을 때까지 반복
			while (LFirst(&pg->adjList[i], &vx))
				LRemove(&pg->adjList[i]);	// 정점의 간선 정보를 담고있는 노드를 모두 삭제한다.	

			// 더미노드 삭제
			free(pg->adjList[i].head);
		}

		free(pg->adjList);	// 그래프에 할당된 간선 정보를 삭제한다.
	}

	if (pg->queueInfo != NULL)
		free(pg->queueInfo);
}

void AddEdge(ALGraph * pg, int fromV, int toV)
{
	// 정점 fromV의 연결 리스트에 정점 toV의 정보 추가
	LInsert(&(pg->adjList[fromV]), toV);

	// 정점 toV의 연결 리스트에 정점 fromV의 정보 추가
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

void ShowGraphEdgeInfo(ALGraph * pg)
{
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++)
	{
		printf("%c와 연결된 정점: ", i + 65);
		if (LFirst(&(pg->adjList[i]), &vx))
		{
			printf("%c ", vx + 65);

			while (LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}

// 큐에 들어간 Vertex 마킹
void MarkVertex(ALGraph * pg, int pushedV)
{
	pg->queueInfo[pushedV] = 1;	// stack에 push된 것으로 기록
}
int IsEnqueuedVertex(ALGraph * pg, int pushedV)
{
	// 해당 정점이 push된 적이 있으면 TRUE, 없으면 FALSE
	return pg->queueInfo[pushedV] == 1;
}
void VisitVertex(int visitV)
{
	printf("%c ", visitV + 65);
}
void BFShowGraphVertex(ALGraph * pg, int startV)
{
    Queue queue;
    int visitV;
    int nextV;

    QueueInit(&queue);			// BFS를 위한 큐의 초기화
    Enqueue(&queue, startV);	// 시작점을 큐에 Enqueue
    MarkVertex(pg, startV);     // startV 정점이 queue에 삽입되었음을 마킹

    do
    {
        // queue의 첫번째 정점을 Dequeue하고 방문할 정점으로 저장
        visitV = Dequeue(&queue);
        VisitVertex(visitV);	// 정점 방문
	
        // 현재 방문한 정점의 인접 정점 중 queue에 들어간 적 없는 정점들 모두 Enqueue 
        if (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
        {
            do
            {
                // queue에 Enqueue된 적 없는 정점이라면 queue에 Enqueue
                if (IsEnqueuedVertex(pg, nextV) == FALSE) 
                {
                    Enqueue(&queue, nextV);
                    MarkVertex(pg, nextV);
                }
            } while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE);
        }
		
    } while (!QIsEmpty(&queue)); // queue가 비어질때 까지 반복


    // 이후의 탐색을 위해서 탐색 정보 초기화
    memset(pg->queueInfo, 0, sizeof(int) * pg->numV);
}
