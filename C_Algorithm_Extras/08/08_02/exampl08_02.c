#include <stdio.h>
#include <stdlib.h>
#include "graphlinkedlist.h"
#include "linkedgraph.h"

int main(int argc, char *argv[])
{
	int i = 0;
	LinkedGraph *pG1 = NULL;
	LinkedGraph *pG2 = NULL;
	LinkedGraph *pG4 = NULL;

	// 그래프 생성
	pG1 = createLinkedGraph(6);
	pG2 = createLinkedDirectedGraph(6);
	pG4 = createLinkedDirectedGraph(6);
	if (pG1 != NULL && pG2 != NULL && pG4 != NULL)
	{
		// 그래프 초기화: 정점 추가
		for(i = 0; i < 6; i++)
		{
			addVertexLG(pG1, i);
			addVertexLG(pG2, i);
			addVertexLG(pG4, i);
		}

		// 그래프 초기화: 간선 추가
		addEdgeLG(pG1, 0, 1);
		addEdgeLG(pG1, 0, 2);
		addEdgeLG(pG1, 1, 2);
		addEdgeLG(pG1, 2, 3);
		addEdgeLG(pG1, 3, 4);
		addEdgeLG(pG1, 3, 5);
		addEdgeLG(pG1, 4, 5);

		addEdgeLG(pG2, 0, 1);
		addEdgeLG(pG2, 1, 2);
		addEdgeLG(pG2, 2, 0);
		addEdgeLG(pG2, 2, 1);
		addEdgeLG(pG2, 2, 3);
		addEdgeLG(pG2, 3, 2);
		addEdgeLG(pG2, 3, 4);
		addEdgeLG(pG2, 4, 5);
		addEdgeLG(pG2, 5, 3);

		addEdgewithWeightLG(pG4, 0, 1, 4);
		addEdgewithWeightLG(pG4, 1, 2, 1);
		addEdgewithWeightLG(pG4, 2, 0, 2);
		addEdgewithWeightLG(pG4, 2, 1, 3);
		addEdgewithWeightLG(pG4, 2, 3, 2);
		addEdgewithWeightLG(pG4, 3, 2, 1);
		addEdgewithWeightLG(pG4, 3, 4, 1);
		addEdgewithWeightLG(pG4, 4, 5, 1);
		addEdgewithWeightLG(pG4, 5, 3, 2);

		// 그래프 정보 출력
		printf("G1: 무방향 그래프\n");
		displayLinkedGraph(pG1);
		printf("\nG2: 방향 그래프\n");
		displayLinkedGraph(pG2);
		printf("\nG3: 방향 가중치 그래프\n");
		displayLinkedGraph(pG4);

		// 그래프 삭제
		deleteLinkedGraph(pG1);
		deleteLinkedGraph(pG2);
		deleteLinkedGraph(pG4);
	}

	return 0;
}
