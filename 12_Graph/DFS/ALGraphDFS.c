#include "ALGraphDFS.h"
#include "ArrayBaseStack.h"
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
	pg->visitInfo = (int*)malloc(sizeof(int) * nv);
	memset(pg->visitInfo, 0, sizeof(int) * nv);

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

	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
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

			while(LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}

int VisitVertex(ALGraph * pg, int visitV)
{
	// visitV에 처음 방문일 때
	if (pg->visitInfo[visitV] == 0)
	{
		pg->visitInfo[visitV] = 1;	// visitV에 방문한 것으로 기록
		printf("%c ", visitV + 65);	// 방문한 정점의 이름을 출력
		return TRUE;				// 방문 성공!
	}
	return FALSE;	// 방문 실패
}

void DFShowGraphVertex(ALGraph * pg, int startV)
{
	Stack stack;
	int visitV = startV;
	int nextV;

	StackInit(&stack);			// DFS를 위한 스택의 초기화
	VisitVertex(pg, visitV);	// 시작 정점을 방문

	// visitV에 담긴 정점과 연결된 정점의 방문을 시도하는 while문
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{

		// visitV와 연결된 정점의 정보가 nextV에 담긴 상태에서 이하를 진행
		int visitFlag = FALSE;

		if (VisitVertex(pg, nextV) == TRUE)	// 방문에 성공했다면,
		{
			SPush(&stack, visitV);	// visitV에 담긴 정점의 정보를 PUSH!
			visitV = nextV;
			visitFlag = TRUE;
		}
		else // 방문에 성공하지 못했다면, 연결된 다른 정점들을 찾는다.
		{
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				if (VisitVertex(pg, nextV) == TRUE)
				{
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if (visitFlag == FALSE)	// 추가로 방문한 정점이 없다면
		{
			// 스택이 비면 탐색의 시작점으로 되돌아 온것!
			if (SIsEmpty(&stack) == TRUE)	// 시작점으로 되돌아 왔음
				break;
			else
				visitV = SPop(&stack);	// 길을 되돌아 간다.
		}
	}

	// 이후의 탐색을 위해서 탐색 정보 초기화
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}
