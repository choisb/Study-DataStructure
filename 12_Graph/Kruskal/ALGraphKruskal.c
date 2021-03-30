#include "ALGraphKruskal.h"
#include "ArrayBaseStack.h"
#include <stdio.h>
#include <stdlib.h>

int WhoIsPrecede(LData data1, LData data2)
{
	return data1 > data2;
}
int PQWeightComp(Edge d1, Edge d2)
{
    return d1.weight - d2.weight;
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
	pg->stackInfo = (int*)malloc(sizeof(int) * nv);
	memset(pg->stackInfo, 0, sizeof(int) * nv);

	// 정점의 수와 간선의 수 초기화
	pg->numV = nv;	// 정점의 수는 nv에 저장된 값으로 결정
	pg->numE = 0;	// 초기의 간선 수는 0개

    // 우선순위 큐의 초기화
    PQueueInit(&(pg->pqueue), PQWeightComp);
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

	if (pg->stackInfo != NULL)
		free(pg->stackInfo);
}

void AddEdge(ALGraph * pg, int fromV, int toV, int weight)
{
    Edge edge = { fromV, toV, weight }; // 간선의 가중치 정보를 담을 포인터
 
	// 정점 fromV의 연결 리스트에 정점 toV의 정보 추가
	LInsert(&(pg->adjList[fromV]), toV);

	// 정점 toV의 연결 리스트에 정점 fromV의 정보 추가
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;

    // 간선의 가중치 정보를 우선순위 큐에 저장
    PEnqueue(&(pg->pqueue), edge);
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

// 스택이 들어간 Vertex 마킹
void MarkVertex(ALGraph * pg, int pushedV)
{
	pg->stackInfo[pushedV] = 1;	// stack에 push된 것으로 기록
}
int IsPushedVertex(ALGraph * pg, int pushedV)
{
	// 해당 정점이 push된 적이 있으면 TRUE, 없으면 FALSE
	return pg->stackInfo[pushedV] == 1;
}
void VisitVertex(int visitV)
{
	printf("%c ", visitV + 65);
}
void DFShowGraphVertex(ALGraph * pg, int startV)
{
	Stack stack;
	int visitV;
	int nextV;

	StackInit(&stack);			// DFS를 위한 스택의 초기화
	SPush(&stack, startV);		// 시작점을 스택에 push
	MarkVertex(pg, startV);

	do
	{
		// 스택의 첫번째 정점을 pop하고 방문할 정점으로 저장
		visitV = SPop(&stack);
        VisitVertex(visitV);	// 정점 방문

		// 현재 방문한 정점의 인접 정점 중 스택에 들어간 적 없는 정점들 모두 Push 
		if (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
		{
			do
			{
				// 스택에 Push된 적 없는 정점이라면 스택에 Push
				if (IsPushedVertex(pg, nextV) == FALSE) {
					SPush(&stack, nextV);
					MarkVertex(pg, nextV);
				}
			} while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE);
		}
		
	} while (!SIsEmpty(&stack)); // 스택이 비어질때 까지 반복


	// 이후의 탐색을 위해서 탐색 정보 초기화
	memset(pg->stackInfo, 0, sizeof(int) * pg->numV);
}

// fromV정점 에서 toV정점으로 향하는 edge를 탐색하여서 삭제
void RemoveWayEdge(ALGraph * pg, int fromV, int toV)
{
    int edge;

    if (LFirst(&(pg->adjList[fromV]), &edge))
    {
        do {
            if (edge == toV)
            {
                LRemove(&(pg->adjList[fromV]));
                return;
            }
        } while (LNext(&(pg->adjList[fromV]), &edge));
    }
}

void RemoveEdge(ALGraph * pg, int fromV, int toV)
{
    RemoveWayEdge(pg, fromV, toV);
    RemoveWayEdge(pg, toV, fromV);
    (pg->numE)--;
}
// v1정점과 v2정점이 연결되어있다면 TRUE, 아니면 FALSE
// DFS search 함수를 수정하여 사용
int IsConnVertex(ALGraph *pg, int v1, int v2)
{
    Stack stack;
    int visitV;
    int nextV;

    StackInit(&stack);			// DFS를 위한 스택의 초기화
    SPush(&stack, v1);		// 시작점을 스택에 push
    MarkVertex(pg, v1);

    do
    {
        // 스택의 첫번째 정점을 pop하고 방문할 정점으로 저장
        visitV = SPop(&stack);
        if (visitV == v2) {
            // 이후의 탐색을 위해서 탐색 정보 초기화
            memset(pg->stackInfo, 0, sizeof(int) * pg->numV);
            return TRUE;
        }

        // 현재 방문한 정점의 인접 정점 중 스택에 들어간 적 없는 정점들 모두 Push 
        if (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
        {
            do
            {
                // 스택에 Push된 적 없는 정점이라면 스택에 Push
                if (IsPushedVertex(pg, nextV) == FALSE) {
                    SPush(&stack, nextV);
                    MarkVertex(pg, nextV);
                }
            } while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE);
        }

    } while (!SIsEmpty(&stack)); // 스택이 비어질때 까지 반복


    // 이후의 탐색을 위해서 탐색 정보 초기화
    memset(pg->stackInfo, 0, sizeof(int) * pg->numV);
    return FALSE;
}
void RecoverEdge(ALGraph * pg, int fromV, int toV)
{
    LInsert(&(pg->adjList[fromV]), toV);
    LInsert(&(pg->adjList[toV]), fromV);
    (pg->numE)++;
}
// 크루스칼 알고리즘 기반 MST 구성
void ConKruskalMST(ALGraph * pg)
{
    Edge recvEdge[20];  // 복원할 간선의 정보 저장
    Edge edge;
    int eidx = 0;
    int i;

    // MST를 형성할 때까지 아래의 while 문을 반복
    while (pg->numE + 1 > pg->numV)
    {
        // 우선순위 큐에서 가중치가 제일 높은 간선의 정보를 꺼낸다.
        edge = PDequeue(&(pg->pqueue));
        // 우선순위 큐에서 꺼낸 간선을 실제로 그래프에서 삭제한다.
        RemoveEdge(pg, edge.v1, edge.v2);

        // 간선을 삭제하고 나서도 두 정점을 연결하는 경로가 있는지 확인한다.
        if (!IsConnVertex(pg, edge.v1, edge.v2))
        {
            // 경로가 없다면 삭제한 간선을 복원한다.
            RecoverEdge(pg, edge.v1, edge.v2);
            // 복원한 간선의 정보를 별도로 저장한다.
            recvEdge[eidx++] = edge;
        }
    }

    // 우선순위 큐에서 삭제된 간선의 정보를 회복
    for (i = 0; i < eidx; i++)
        PEnqueue(&(pg->pqueue), recvEdge[i]);
}

void ShowGraphEdgeWeightInfo(ALGraph * pg)
{
    PQueue copyPQ = pg->pqueue;
    Edge edge;

    while (!PQIsEmpty(&copyPQ))
    {
        edge = PDequeue(&copyPQ);
        printf("(%c-%c), w:%d \n", edge.v1 + 65, edge.v2 + 65, edge.weight);
    }
}
