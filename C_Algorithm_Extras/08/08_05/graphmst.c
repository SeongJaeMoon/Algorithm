#include <stdio.h>
#include <stdlib.h>
#include "graphlinkedlist.h"
#include "linkedstack.h"
#include "linkedgraph.h"
#include "grapharrayheap.h"
#include "graphmst.h"

LinkedGraph* mstKruskal(LinkedGraph* pGraph)
{
	LinkedGraph* pReturn = NULL;
	int i = 0;
	int maxNodeCount = 0;
	int currentNodeCounde = 0;
	int edgeCount = 0;
	int isCycle = 0;
	ArrayMinHeap *pMinHeap = NULL;
	HeapNode *pHeapNode = NULL;

	if (pGraph == NULL) {
		printf("Graph is NULL\n");
		return NULL;
	}

	maxNodeCount = getMaxVertexCountLG(pGraph);
	currentNodeCounde = getVertexCountLG(pGraph);
	edgeCount = getEdgeCountLG(pGraph);

	pReturn = createLinkedGraph(maxNodeCount);
	if (pReturn == NULL) {
		return NULL;
	}
	pMinHeap = orderEdges(pGraph);
	if (pMinHeap == NULL) {
		return NULL;
	}
	for(i = 0; i < edgeCount; i++) {
		pHeapNode = deleteMinHeapAH(pMinHeap);
		if (pHeapNode != NULL) {
			isCycle = checkCycle(pReturn, pHeapNode->fromVertexID, 
								pHeapNode->toVertexID);
			if (isCycle == FALSE) {
				if (pReturn->pVertex[pHeapNode->fromVertexID] != USED) {
					addVertexLG(pReturn, pHeapNode->fromVertexID);
				}
				if (pReturn->pVertex[pHeapNode->toVertexID] != USED) {
					addVertexLG(pReturn, pHeapNode->toVertexID);
				}
				addEdgewithWeightLG(pReturn, pHeapNode->fromVertexID, 
						pHeapNode->toVertexID, pHeapNode->key);
				printf("[%d], 최소 가중치: (%d,%d)->%d\n", 
						i, pHeapNode->fromVertexID, pHeapNode->toVertexID, 
						pHeapNode->key);
			}
			free(pHeapNode);

			if (getVertexCountLG(pReturn) == currentNodeCounde) {
				break;
			}
		}
	}

	return pReturn;
}

ArrayMinHeap *orderEdges(LinkedGraph* pGraph) {
	int i = 0;
	int edgeCount = 0;
	ArrayMinHeap *pReturn = NULL;
	ListNode *pListNode = NULL;
	LinkedList* pEdgeList = NULL;

	if (pGraph == NULL) {
		printf("Graph is NULL\n");
		return pReturn;
	}

	edgeCount = getEdgeCountLG(pGraph);
	if (edgeCount == 0) {
		printf("오류, 간선 개수가 0개\n");
		return pReturn;
	}

	pReturn = createArrayMinHeap(edgeCount);
	if (pReturn == NULL) {
		return pReturn;
	}

	for(i = 0; i < pGraph->maxVertexCount; i++) {
		if (pGraph->pVertex[i] == USED) {
			pEdgeList = pGraph->ppAdjEdge[i];
			pListNode = pEdgeList->headerNode.pLink;
			while(pListNode != NULL) {
				int vertexID = pListNode->data.vertexID;
				int weight = pListNode->data.weight;

				// 무방향 그래프라면, 동일한 간선이 2개 리턴되므로,
				// 시작 노드 id가 종료 노드 id보다 작은 경우만 리턴되도록 한다.
				// 즉, 간선 1개만 리턴되도록 한다.
				if (pGraph->graphType == GRAPH_DIRECTED
					|| (pGraph->graphType == GRAPH_UNDIRECTED && i < vertexID)) {
					HeapNode heapNode = {0,};
					heapNode.fromVertexID = i;
					heapNode.toVertexID = vertexID;
					heapNode.key = weight;
					insertMinHeapAH(pReturn, heapNode);
				}

				pListNode = pListNode->pLink;
			}
		}
	}

	return pReturn;
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
