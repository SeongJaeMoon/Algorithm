#include <stdio.h>
#include <stdlib.h>
#include "graphlinkedlist.h"
#include "linkedgraph.h"
#include "graphtraversal.h"

int main(int argc, char *argv[])
{
	int i = 0;
	LinkedGraph *pG1 = NULL;

	// 그래프 생성
	pG1 = createLinkedGraph(8);
	if (pG1 != NULL)
	{
		// 그래프 초기화: 정점 추가
		for(i = 0; i < 8; i++)
		{
			addVertexLG(pG1, i);
		}

		// 그래프 초기화: 간선 추가
		addEdgeLG(pG1, 0, 1);
		addEdgeLG(pG1, 0, 2);
		addEdgeLG(pG1, 1, 3);
		addEdgeLG(pG1, 1, 4);
		addEdgeLG(pG1, 2, 5);
		addEdgeLG(pG1, 2, 6);
		addEdgeLG(pG1, 3, 7);
		addEdgeLG(pG1, 4, 5);

		printf("G1:\n");
		displayLinkedGraph(pG1);

		// BFS 그래프 탐색
		printf("\nBFS traversal:\n");
		traversalBFS(pG1, 0);

		// 그래프 삭제
		deleteLinkedGraph(pG1);
	}

	return 0;
}
