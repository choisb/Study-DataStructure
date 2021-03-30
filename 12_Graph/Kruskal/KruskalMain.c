#include <stdio.h>
#include "ALGraphKruskal.h"

int main()
{
	ALGraph graph;	// �׷����� ����
	GraphInit(&graph, 4);

	AddEdge(&graph, A, B, 3);	
	AddEdge(&graph, A, D, 9);	
	AddEdge(&graph, A, C, 7);	
	AddEdge(&graph, B, C, 5);	
	AddEdge(&graph, D, C, 11);	

    printf("�Էµ� ��������\n");
	ShowGraphEdgeInfo(&graph);	// �׷����� �������� ���
    ShowGraphEdgeWeightInfo(&graph);

    ConKruskalMST(&graph);  // MST�� ��ȯ
    printf("\nMST�� ��ȯ�� ��������\n");
    ShowGraphEdgeInfo(&graph);	// �׷����� �������� ���
    ShowGraphEdgeWeightInfo(&graph);

	GraphDestroy(&graph);		// �׷����� ���ҽ� �Ҹ�

	return 0;
}