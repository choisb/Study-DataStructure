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

    // �켱���� ť�� �ʱ�ȭ
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

void AddEdge(ALGraph * pg, int fromV, int toV, int weight)
{
    Edge edge = { fromV, toV, weight }; // ������ ����ġ ������ ���� ������
 
	// ���� fromV�� ���� ����Ʈ�� ���� toV�� ���� �߰�
	LInsert(&(pg->adjList[fromV]), toV);

	// ���� toV�� ���� ����Ʈ�� ���� fromV�� ���� �߰�
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;

    // ������ ����ġ ������ �켱���� ť�� ����
    PEnqueue(&(pg->pqueue), edge);
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

// fromV���� ���� toV�������� ���ϴ� edge�� Ž���Ͽ��� ����
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
// v1������ v2������ ����Ǿ��ִٸ� TRUE, �ƴϸ� FALSE
// DFS search �Լ��� �����Ͽ� ���
int IsConnVertex(ALGraph *pg, int v1, int v2)
{
    Stack stack;
    int visitV;
    int nextV;

    StackInit(&stack);			// DFS�� ���� ������ �ʱ�ȭ
    SPush(&stack, v1);		// �������� ���ÿ� push
    MarkVertex(pg, v1);

    do
    {
        // ������ ù��° ������ pop�ϰ� �湮�� �������� ����
        visitV = SPop(&stack);
        if (visitV == v2) {
            // ������ Ž���� ���ؼ� Ž�� ���� �ʱ�ȭ
            memset(pg->stackInfo, 0, sizeof(int) * pg->numV);
            return TRUE;
        }

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
    return FALSE;
}
void RecoverEdge(ALGraph * pg, int fromV, int toV)
{
    LInsert(&(pg->adjList[fromV]), toV);
    LInsert(&(pg->adjList[toV]), fromV);
    (pg->numE)++;
}
// ũ�罺Į �˰��� ��� MST ����
void ConKruskalMST(ALGraph * pg)
{
    Edge recvEdge[20];  // ������ ������ ���� ����
    Edge edge;
    int eidx = 0;
    int i;

    // MST�� ������ ������ �Ʒ��� while ���� �ݺ�
    while (pg->numE + 1 > pg->numV)
    {
        // �켱���� ť���� ����ġ�� ���� ���� ������ ������ ������.
        edge = PDequeue(&(pg->pqueue));
        // �켱���� ť���� ���� ������ ������ �׷������� �����Ѵ�.
        RemoveEdge(pg, edge.v1, edge.v2);

        // ������ �����ϰ� ������ �� ������ �����ϴ� ��ΰ� �ִ��� Ȯ���Ѵ�.
        if (!IsConnVertex(pg, edge.v1, edge.v2))
        {
            // ��ΰ� ���ٸ� ������ ������ �����Ѵ�.
            RecoverEdge(pg, edge.v1, edge.v2);
            // ������ ������ ������ ������ �����Ѵ�.
            recvEdge[eidx++] = edge;
        }
    }

    // �켱���� ť���� ������ ������ ������ ȸ��
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
