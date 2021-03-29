#include <stdio.h>
#include "ALGraphDFS2.h"

int main()
{
	ALGraph graph;	// 그래프의 생성
	GraphInit(&graph, 6);

	AddEdge(&graph, A, B);	
	AddEdge(&graph, A, D);	
	AddEdge(&graph, B, C);	
	AddEdge(&graph, D, C);	
	AddEdge(&graph, C, E);	
	AddEdge(&graph, C, F);
	AddEdge(&graph, E, F);

	ShowGraphEdgeInfo(&graph);	// 그래프의 간선정보 출력

	DFShowGraphVertex(&graph, A);
	printf("\n");
	//DFShowGraphVertex(&graph, C);
	//printf("\n");
	//DFShowGraphVertex(&graph, E);
	//printf("\n");
	//DFShowGraphVertex(&graph, G);
	//printf("\n");


	GraphDestroy(&graph);		// 그래프의 리소스 소멸

	return 0;
}