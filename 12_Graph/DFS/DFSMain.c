#include <stdio.h>
#include "ALGraphDFS.h"

int main()
{
	ALGraph graph;	// 그래프의 생성
	GraphInit(&graph, 7);

	AddEdge(&graph, A, B);	
	AddEdge(&graph, A, D);	
	AddEdge(&graph, B, C);	
	AddEdge(&graph, D, C);	
	AddEdge(&graph, D, E);	
	AddEdge(&graph, E, F);
	AddEdge(&graph, E, G);

	ShowGraphEdgeInfo(&graph);	// 그래프의 간선정보 출력

	DFShowGraphVertex(&graph, A);
	printf("\n");
	DFShowGraphVertex(&graph, C);
	printf("\n");
	DFShowGraphVertex(&graph, E);
	printf("\n");
	DFShowGraphVertex(&graph, G);
	printf("\n");


	GraphDestroy(&graph);		// 그래프의 리소스 소멸

	return 0;
}