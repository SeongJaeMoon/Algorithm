#include <stdio.h>
#include <stdlib.h>
#include "graphlinkedlist.h"
#include "linkedgraph.h"
#include "linkedqueue.h"
#include "graphtraversal.h"

int enqueueLQForBFS(LinkedQueue* pQueue, int nodeID)
{
	QueueNode node = {0, };
	node.data = nodeID;
	return enqueueLQ(pQueue, node);
}


// BFS 그래프 탐색
void traversalBFS(LinkedGraph* pGraph, int startVertexID)
{
	int i = 0;
	int vertextID = 0;
	QueueNode *pTop = NULL;
	LinkedQueue* pQueue = NULL;
	QueueNode* pQueueNode = NULL; 
	ListNode *pListNode = NULL;
	int *pVisited = NULL;

	if (pGraph == NULL) {
		return;
	}

	pQueue = createLinkedQueue();
	if (pQueue == NULL) {
		return;
	}

	pVisited = (int*) malloc(sizeof(int) * pGraph->maxVertexCount);
	if (pVisited == NULL) {
		printf("Error, malloc() in traversalDFS()\n");
		return;
	}

	// 초기화.
	for(i = 0; i < pGraph->maxVertexCount; i++) {
		pVisited[i] = FALSE;
	}

	pVisited[startVertexID] = TRUE;
	enqueueLQForBFS(pQueue, startVertexID);

	while(isLinkedQueueEmpty(pQueue) == FALSE) {
		pQueueNode = dequeueLQ(pQueue);
		if (pQueueNode != NULL) {
			vertextID = pQueueNode->data;
			printf("[%d]-visited\n", vertextID);

			pListNode = pGraph->ppAdjEdge[vertextID]->headerNode.pLink;
			while(pListNode != NULL) {
				int vertexID = pListNode->data.vertexID;
				if (pVisited[vertexID] == FALSE) {
					pVisited[vertexID] = TRUE;
					enqueueLQForBFS(pQueue, vertexID);
				}

				pListNode = pListNode->pLink;
			}
		}
	}

	free(pVisited);
	deleteLinkedQueue(pQueue);
}
