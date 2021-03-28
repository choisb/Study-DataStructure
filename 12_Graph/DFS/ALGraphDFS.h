#ifndef __AL_GRAPHDFS_H__
#define __AL_GRAPHDFS_H__

#include "DLinkedList.h"

// ������ �̸��� ���ȭ
enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual
{
	int numV;		// ������ ��
	int numE;		// ������ ��
	List * adjList;	// ������ ����
	int * visitInfo;	// Ž���� ����� ������ ������ ��� ����
}ALGraph;

// �׷����� �ʱ�ȭ
void GraphInit(ALGraph * pg, int nv);

// �׷����� ���ҽ� ����
void GraphDestroy(ALGraph * pg);

// ������ �߰�
void AddEdge(ALGraph * pg, int fromV, int toV);

// ������ ���� ���
void ShowGraphEdgeInfo(ALGraph * pg);

// ������ ���� ���: Depth First Search ���
void DFShowGraphVertex(ALGraph * pg, int startV);

#endif