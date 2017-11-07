#include <stdio.h>
#include <stdlib.h>
#include "graphlinkedlist.h"
#include "linkedgraph.h"
#include "grapharrayheap.h"
#include "graphmst.h"

int main(int argc, char *argv[])
{
	int i = 0;
	LinkedGraph *pG1 = NULL;
	LinkedGraph *pMST1 = NULL;

	// 그래프 생성
	pG1 = createLinkedGraph(6);
	if (pG1 != NULL) {
		// 그래프 초기화: 노드 추가
		for(i = 0; i < 6; i++) {
			addVertexLG(pG1, i);
		}

		// 그래프 초기화: 간선 추가
		addEdgewithWeightLG(pG1, 0, 1, 4);
		addEdgewithWeightLG(pG1, 0, 2, 3);
		addEdgewithWeightLG(pG1, 1, 2, 2);
		addEdgewithWeightLG(pG1, 2, 3, 1);
		addEdgewithWeightLG(pG1, 3, 4, 1);
		addEdgewithWeightLG(pG1, 3, 5, 5);
		addEdgewithWeightLG(pG1, 4, 5, 6);

		printf("G1:\n");
		displayLinkedGraph(pG1);

		// Kruskal 알고리즘으로 MST 생성
		printf("\nKruskal MST:\n");
		pMST1 = mstKruskal(pG1);
		displayLinkedGraph(pMST1);

		// 그래프 삭제
		deleteLinkedGraph(pG1);
		deleteLinkedGraph(pMST1);
	}

	return 0;
}
