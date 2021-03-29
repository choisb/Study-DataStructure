#include <stdio.h>
#include "ALGraphBFS.h"

int main()
{
	ALGraph graph;	// �׷����� ����
	GraphInit(&graph, 6);

	AddEdge(&graph, A, B);	
	AddEdge(&graph, A, D);	
	AddEdge(&graph, B, C);	
	AddEdge(&graph, D, C);	
	AddEdge(&graph, C, E);	
	AddEdge(&graph, C, F);
	AddEdge(&graph, E, F);

	ShowGraphEdgeInfo(&graph);	// �׷����� �������� ���

	BFShowGraphVertex(&graph, A);
	printf("\n");
	//DFShowGraphVertex(&graph, C);
	//printf("\n");
	//DFShowGraphVertex(&graph, E);
	//printf("\n");
	//DFShowGraphVertex(&graph, G);
	//printf("\n");


	GraphDestroy(&graph);		// �׷����� ���ҽ� �Ҹ�

	return 0;
}