#include <stdio.h>
#include "ALGraph.h"

int WhoIsPrecede(LData data1, LData data2)
{
	return data1 > data2;
}

void GraphInit(ALGraph * pg, int nv)
{
	int i;

	// ������ ���� �ش��ϴ� ������ ����Ʈ �迭�� �����Ѵ�.
	pg->adjList = (List*)malloc(sizeof(List) * nv);	// ���������� ������ ����Ʈ ����

	pg->numV = nv;	// ������ ���� nv�� ����� ������ ����
	pg->numE = 0;	// �ʱ��� ���� ���� 0��

	// ������ ����ŭ ������ ����Ʈ���� �ʱ�ȭ�Ѵ�.
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
			// ����Ʈ�� ����� ��尡 ���� ������ �ݺ�
			while (LFirst(&pg->adjList[i], &vx))				
				LRemove(&pg->adjList[i]);	// ������ ���� ������ ����ִ� ��带 ��� �����Ѵ�.	

			// ���̳�� ����
			free(pg->adjList[i].head);			
		}

		free(pg->adjList);	// �׷����� �Ҵ�� ���� ������ �����Ѵ�.
	}
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