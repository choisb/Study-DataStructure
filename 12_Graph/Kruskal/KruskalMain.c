#include <stdio.h>
#include "ALGraphKruskal.h"

int main()
{
	ALGraph graph;	// 그래프의 생성
	GraphInit(&graph, 4);

	AddEdge(&graph, A, B, 3);	
	AddEdge(&graph, A, D, 9);	
	AddEdge(&graph, A, C, 7);	
	AddEdge(&graph, B, C, 5);	
	AddEdge(&graph, D, C, 11);	

    printf("입력된 간선정보\n");
	ShowGraphEdgeInfo(&graph);	// 그래프의 간선정보 출력
    ShowGraphEdgeWeightInfo(&graph);

    ConKruskalMST(&graph);  // MST로 변환
    printf("\nMST로 변환된 간선정보\n");
    ShowGraphEdgeInfo(&graph);	// 그래프의 간선정보 출력
    ShowGraphEdgeWeightInfo(&graph);

	GraphDestroy(&graph);		// 그래프의 리소스 소멸

	return 0;
}