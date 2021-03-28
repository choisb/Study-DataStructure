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

	// ������ ���� �ش��ϴ� ������ ����Ʈ �迭�� �����Ѵ�.
	pg->adjList = (List*)malloc(sizeof(List) * nv);	// ���������� ������ ����Ʈ ����

	// ������ ����ŭ ������ ����Ʈ���� �ʱ�ȭ�Ѵ�.
	for (i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}

	// �湮 ������ �����ϱ� ���ؼ� ������ ���� ���� ũ���� �迭�� �Ҵ��ϰ� �ʱ�ȭ
	pg->visitInfo = (int*)malloc(sizeof(int) * nv);
	memset(pg->visitInfo, 0, sizeof(int) * nv);

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

	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
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

			while(LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}

int VisitVertex(ALGraph * pg, int visitV)
{
	// visitV�� ó�� �湮�� ��
	if (pg->visitInfo[visitV] == 0)
	{
		pg->visitInfo[visitV] = 1;	// visitV�� �湮�� ������ ���
		printf("%c ", visitV + 65);	// �湮�� ������ �̸��� ���
		return TRUE;				// �湮 ����!
	}
	return FALSE;	// �湮 ����
}

void DFShowGraphVertex(ALGraph * pg, int startV)
{
	Stack stack;
	int visitV = startV;
	int nextV;

	StackInit(&stack);			// DFS�� ���� ������ �ʱ�ȭ
	VisitVertex(pg, visitV);	// ���� ������ �湮

	// visitV�� ��� ������ ����� ������ �湮�� �õ��ϴ� while��
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{

		// visitV�� ����� ������ ������ nextV�� ��� ���¿��� ���ϸ� ����
		int visitFlag = FALSE;

		if (VisitVertex(pg, nextV) == TRUE)	// �湮�� �����ߴٸ�,
		{
			SPush(&stack, visitV);	// visitV�� ��� ������ ������ PUSH!
			visitV = nextV;
			visitFlag = TRUE;
		}
		else // �湮�� �������� ���ߴٸ�, ����� �ٸ� �������� ã�´�.
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

		if (visitFlag == FALSE)	// �߰��� �湮�� ������ ���ٸ�
		{
			// ������ ��� Ž���� ���������� �ǵ��� �°�!
			if (SIsEmpty(&stack) == TRUE)	// ���������� �ǵ��� ����
				break;
			else
				visitV = SPop(&stack);	// ���� �ǵ��� ����.
		}
	}

	// ������ Ž���� ���ؼ� Ž�� ���� �ʱ�ȭ
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}
