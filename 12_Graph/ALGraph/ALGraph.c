#include <stdio.h>
#include "ALGraph.h"

int WhoIsPrecede(LData data1, LData data2)
{
	return data1 > data2;
}

void GraphInit(ALGraph * pg, int nv)
{
	int i;

	// 정점의 수에 해당하는 길이의 리스트 배열을 생성한다.
	pg->adjList = (List*)malloc(sizeof(List) * nv);	// 간선정보를 저장할 리스트 생성

	pg->numV = nv;	// 정점의 수는 nv에 저장된 값으로 결정
	pg->numE = 0;	// 초기의 간선 수는 0개

	// 정점의 수만큼 생성된 리스트들을 초기화한다.
	for (i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}
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