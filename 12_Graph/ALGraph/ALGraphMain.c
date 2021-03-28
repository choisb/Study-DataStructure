#include "ALGraph.h"

int main()
{
	ALGraph graph;	// �׷����� ����
	GraphInit(&graph, 5);

	AddEdge(&graph, A, B);	// ���� A�� B�� ����
	AddEdge(&graph, A, D);	// ���� A�� D�� ����
	AddEdge(&graph, B, C);	// ���� B�� C�� ����
	AddEdge(&graph, C, D);	// ���� C�� D�� ����
	AddEdge(&graph, D, E);	// ���� D�� E�� ����
	AddEdge(&graph, E, A);	// ���� E�� A�� ����

	ShowGraphEdgeInfo(&graph);	// �׷����� �������� ���
	GraphDestroy(&graph);		// �׷����� ���ҽ� �Ҹ�

	return 0;
}