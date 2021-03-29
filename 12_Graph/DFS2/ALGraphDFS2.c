#include "ALGraphDFS2.h"
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

	// ������ ���� �ش��ϴ� ������ ����Ʈ �迭�� �����Ѵ�.
	pg->adjList = (List*)malloc(sizeof(List) * nv);	// ���������� ������ ����Ʈ ����

	// ������ ����ŭ ������ ����Ʈ���� �ʱ�ȭ�Ѵ�.
	for (i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}

	// �湮 ������ �����ϱ� ���ؼ� ������ ���� ���� ũ���� �迭�� �Ҵ��ϰ� �ʱ�ȭ
	pg->stackInfo = (int*)malloc(sizeof(int) * nv);
	memset(pg->stackInfo, 0, sizeof(int) * nv);

	// ������ ���� ������ �� �ʱ�ȭ
	pg->numV = nv;	// ������ ���� nv�� ����� ������ ����
	pg->numE = 0;	// �ʱ��� ���� ���� 0��
}

void GraphDestroy(ALGraph * pg)
{
	int i;
	int vx;

	if (pg->adjList != NULL)
	{
		for (i = 0; i < pg->numV; i++)
		{
			// ����Ʈ�� ����� ��尡 ���� ������ �ݺ�
			while (LFirst(&pg->adjList[i], &vx))
				LRemove(&pg->adjList[i]);	// ������ ���� ������ ����ִ� ��带 ��� �����Ѵ�.	

			// ���̳�� ����
			free(pg->adjList[i].head);
		}

		free(pg->adjList);	// �׷����� �Ҵ�� ���� ������ �����Ѵ�.
	}

	if (pg->stackInfo != NULL)
		free(pg->stackInfo);
}

void AddEdge(ALGraph * pg, int fromV, int toV)
{
	// ���� fromV�� ���� ����Ʈ�� ���� toV�� ���� �߰�
	LInsert(&(pg->adjList[fromV]), toV);

	// ���� toV�� ���� ����Ʈ�� ���� fromV�� ���� �߰�
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

void ShowGraphEdgeInfo(ALGraph * pg)
{
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++)
	{
		printf("%c�� ����� ����: ", i + 65);
		if (LFirst(&(pg->adjList[i]), &vx))
		{
			printf("%c ", vx + 65);

			while (LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}

// ������ �� Vertex ��ŷ
void MarkVertex(ALGraph * pg, int pushedV)
{
	pg->stackInfo[pushedV] = 1;	// stack�� push�� ������ ���
}
int IsPushedVertex(ALGraph * pg, int pushedV)
{
	// �ش� ������ push�� ���� ������ TRUE, ������ FALSE
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

	StackInit(&stack);			// DFS�� ���� ������ �ʱ�ȭ
	SPush(&stack, startV);		// �������� ���ÿ� push
	MarkVertex(pg, startV);

	do
	{
		// ������ ù��° ������ pop�ϰ� �湮�� �������� ����
		visitV = SPop(&stack);
		VisitVertex(visitV);	// ���� �湮
	
		// ���� �湮�� ������ ���� ���� �� ���ÿ� �� �� ���� ������ ��� Push 
		if (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
		{
			do
			{
				// ���ÿ� Push�� �� ���� �����̶�� ���ÿ� Push
				if (IsPushedVertex(pg, nextV) == FALSE) {
					SPush(&stack, nextV);
					MarkVertex(pg, nextV);
				}
			} while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE);
		}
		
	} while (!SIsEmpty(&stack)); // ������ ������� ���� �ݺ�


	// ������ Ž���� ���ؼ� Ž�� ���� �ʱ�ȭ
	memset(pg->stackInfo, 0, sizeof(int) * pg->numV);
}
