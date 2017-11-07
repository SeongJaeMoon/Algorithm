#include <stdio.h>
#include <stdlib.h>
#include "graphlinkedlist.h"
#include "linkedstack.h"
#include "linkedgraph.h"
#include "graphmst.h"

// Prim 알고리즘
LinkedGraph* mstPrim(LinkedGraph* pGraph, int startVertexID)
{
	LinkedGraph* pReturn = NULL;
	int i = 0;
	int nodeCount = 0;
	int mstNodeCount = 0;
	int maxNodeCount = 0;
	int fromVertexID = 0;
	GraphEdge	minWeightEdge = {0,};

	if (pGraph == NULL) {
		printf("Graph is NULL\n");
		return pReturn;
	}

	nodeCount = getVertexCountLG(pGraph);
	maxNodeCount = getMaxVertexCountLG(pGraph);

	pReturn = createLinkedGraph(maxNodeCount);
	if (pReturn == NULL) {
		return pReturn;
	}
	addVertexLG(pReturn, startVertexID);

	while((mstNodeCount = getVertexCountLG(pReturn)) < nodeCount) {
		minWeightEdge.vertexIDFrom = 0;
		minWeightEdge.vertexIDTo = 0;
		minWeightEdge.weight = MAX_INT;

		for(i = 0; i < maxNodeCount; i++) {
			if (pReturn->pVertex[i] == TRUE) {
				fromVertexID = i;

				getMinWeightEdge(pGraph, pReturn, fromVertexID, &minWeightEdge);
			}
		}
		printf("[%d], 최소 가중치: (%d,%d)->%d\n", 
				mstNodeCount, minWeightEdge.vertexIDFrom, minWeightEdge.vertexIDTo,
				minWeightEdge.weight);
		addVertexLG(pReturn, minWeightEdge.vertexIDTo);
		addEdgewithWeightLG(pReturn, minWeightEdge.vertexIDFrom, 
				minWeightEdge.vertexIDTo, minWeightEdge.weight);
	}

	return pReturn;
}

// 정점(fromVertexID)과 부속된 모든 간선들 중, 
// 가중치가 가장 작으면서 순환을 발생시키지 않는 간선을 선택.
void getMinWeightEdge(LinkedGraph* pGraph, LinkedGraph* pMST,
					int fromVertexID, GraphEdge *pMinWeightEdge) {
	ListNode *pListNode = NULL;
	int isCycle = 0;
	int isAlready = 0;
	LinkedList *pEdgeList = pGraph->ppAdjEdge[fromVertexID];

	// pListNode: V(T)에 부속된 간선들 중 하나를 선택.
	pListNode = pEdgeList->headerNode.pLink;
	while(pListNode != NULL) {
		int vertexID = pListNode->data.vertexID;
		int weight = pListNode->data.weight;

		// 최소값인지 점검.
		if (pListNode->data.weight < pMinWeightEdge->weight) {
			// 기존의 E(T)에 속한 간선인지 점검
			isAlready = checkEdge(pMST, fromVertexID, vertexID);
			if (isAlready == FALSE) {
				// 순환을 발생시키는지 점검
				isCycle = checkCycle(pMST, fromVertexID, vertexID);
			}
			// 기존에 이미 E(T)에 속한 간선이 아니면서,
			// 순환을 발생시키지 않는,
			// 최소 가중치 간선을 선택.
			if (isAlready == FALSE && isCycle == FALSE) {
				pMinWeightEdge->vertexIDFrom = fromVertexID;
				pMinWeightEdge->vertexIDTo = vertexID;
				pMinWeightEdge->weight = weight;
			}
		}

		pListNode = pListNode->pLink;
	}
}

int checkEdge(LinkedGraph* pGraph, int fromVertexID, int toVertexID) {
	int ret = FALSE;
	LinkedList* pEdgeList = NULL;
	int position = 0;

	if (pGraph != NULL) {
		pEdgeList = pGraph->ppAdjEdge[fromVertexID];
		position = findGraphNodePosition(pEdgeList, toVertexID);
		if (position >= 0) {
			ret = TRUE;
		}
	}

	return ret;
}

int pushLSForDFS(LinkedStack* pStack, int nodeID)
{
	StackNode node = {0,};
	node.data = nodeID;
	return pushLS(pStack, node);
}

// 간선 추가로 인해 순환이 발생하는 지 검사.
// 기존에 경로가 있었다면, 순환이 발생한다.
// 기존의 깊이우선탐색(DFS)를 사용.
int checkCycle(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	int pReturn = FALSE;

	int i = 0;
	int vertextID = 0;
	LinkedStack* pStack = NULL;
	StackNode* pStackNode = NULL; 
	ListNode *pListNode = NULL;
	int *pVisited = NULL;

	if (pGraph == NULL) {
		return pReturn;
	}

	pStack = createLinkedStack();
	if (pStack == NULL) {
		return pReturn;
	}

	pVisited = (int*) malloc(sizeof(int) * pGraph->maxVertexCount);
	if (pVisited == NULL) {
		printf("Error, malloc() in traversalDFS()\n");
		deleteLinkedStack(pStack);
		return pReturn;
	}

	// 초기화.
	for(i = 0; i < pGraph->maxVertexCount; i++) {
		pVisited[i] = FALSE;
	}
	
	pVisited[fromVertexID] = TRUE;
	pushLSForDFS(pStack, fromVertexID);

	while(isLinkedStackEmpty(pStack) == FALSE) {
		pStackNode = popLS(pStack);
		if (pStackNode != NULL) {
			vertextID = pStackNode->data;
			if (vertextID == toVertexID) {
				printf("(%d,%d)-기존에 경로가 존재합니다.\n", 
						fromVertexID, toVertexID);
				pReturn = TRUE;
				break;
			}

			pListNode = pGraph->ppAdjEdge[vertextID]->headerNode.pLink;
			while(pListNode != NULL) {
				int vertexID = pListNode->data.vertexID;
				if (pVisited[vertexID] == FALSE) {
					pVisited[vertexID] = TRUE;
					pushLSForDFS(pStack, vertexID);
				}

				pListNode = pListNode->pLink;
			}
		}
	}

	free(pVisited);
	deleteLinkedStack(pStack);

	return pReturn;
}
