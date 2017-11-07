#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphlinkedlist.h"
#include "linkedgraph.h"

LinkedGraph* createLinkedGraph(int maxVertexCount)
{
	int i = 0, j = 0;
	LinkedGraph *pReturn = NULL;

	if (maxVertexCount > 0)	{
		pReturn = (LinkedGraph *)malloc(sizeof(LinkedGraph));
		if (pReturn == NULL) {
			printf("오류, 메모리할당(1), in createLinkedGraph()\n");
			return NULL;
		}
		pReturn->graphType = GRAPH_UNDIRECTED;
		pReturn->maxVertexCount = maxVertexCount;
		pReturn->currentEdgeCount = 0;
		pReturn->currentVertexCount = 0;
	}
	else {
		printf("오류, 최대 노드 개수는 0보다 커야합니다\n");
		return NULL;
	}

	pReturn->pVertex = (int *)malloc(sizeof(int) * maxVertexCount);
	if (pReturn->pVertex == NULL) {
		printf("오류, 메모리할당(2), in createArrayGraph()\n");
		if (pReturn != NULL)  free(pReturn);
		return NULL;
	}
	memset(pReturn->pVertex, NOT_USED, sizeof(int) * maxVertexCount);

	pReturn->ppAdjEdge = (LinkedList **)malloc(sizeof(LinkedList*) * maxVertexCount);
	if (pReturn->ppAdjEdge == NULL) {
		printf("오류, 메모리할당(3), in createLinkedGraph()\n");
		if (pReturn->pVertex != NULL)  free(pReturn->pVertex);
		if (pReturn != NULL)  free(pReturn);
		return NULL;
	}
	for(i = 0; i < maxVertexCount; i++) {
		pReturn->ppAdjEdge[i] = createLinkedList();
		if (pReturn->ppAdjEdge[i] == NULL) {
			printf("오류, 메모리할당(4), in createLinkedGraph()\n");
			for(j = 0; j < i-1; j++) {
				if (pReturn->ppAdjEdge[j] != NULL) free(pReturn->ppAdjEdge[j]);
			}
			if (pReturn->ppAdjEdge != NULL)  free(pReturn->ppAdjEdge);
			if (pReturn->pVertex != NULL)  free(pReturn->pVertex);
			if (pReturn != NULL)  free(pReturn);
			return NULL;
		}
	}

	return pReturn;
}

LinkedGraph* createLinkedDirectedGraph(int maxVertexCount)
{
	LinkedGraph* pReturn = NULL;

	pReturn = createLinkedGraph(maxVertexCount);
	if (pReturn != NULL) {
		pReturn->graphType = GRAPH_DIRECTED;
	}

	return pReturn;
}

// 노드 추가
int addVertexLG(LinkedGraph* pGraph, int vertexID)
{
	int ret = SUCCESS;

	if (pGraph != NULL) {
		if (vertexID < pGraph->maxVertexCount) {
			if (pGraph->pVertex[vertexID] == NOT_USED) {
				pGraph->pVertex[vertexID] = USED;
				pGraph->currentVertexCount++;
			}
			else {
				printf("오류, 노드 ID(1) [%d],in addVertexLG()\n", 
						vertexID);
				ret = FAIL;
			}
		}
		else {
			printf("오류, 노드 ID(2) [%d], in addVertexLG()\n",
					vertexID, pGraph->maxVertexCount);
			ret = FAIL;
		}
	}

	return ret;
}

// 간선 추가.
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	return addEdgewithWeightLG(pGraph, fromVertexID, toVertexID, USED);
}

int addLLElementForVertex(LinkedList* pList, int position, GraphVertex vertex)
{
	ListNode node = {0,};
	node.data = vertex;
	return addLLElement(pList, position, node);
}

int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	int ret = SUCCESS;
	GraphVertex toNode = {0,};

	if (pGraph != NULL)
	{
		if (checkVertexValid(pGraph, fromVertexID) != SUCCESS) {
			ret = FAIL;
			return ret;
		}
		if (checkVertexValid(pGraph, toVertexID) != SUCCESS) {
			ret = FAIL;
			return ret;
		}

		toNode.vertexID = toVertexID;
		toNode.weight = weight;
		addLLElementForVertex(pGraph->ppAdjEdge[fromVertexID], 0, toNode);
		pGraph->currentEdgeCount++;

		// 무방향 그래프의 대칭성(Symmetry) 처리.
		// 방향 그래프라면 필요없음.
		if (pGraph->graphType == GRAPH_UNDIRECTED) {
			GraphVertex fromNode;
			fromNode.vertexID = fromVertexID;
			fromNode.weight = weight;
			addLLElementForVertex(pGraph->ppAdjEdge[toVertexID], 0, fromNode);
			pGraph->currentEdgeCount++;
		}
	}

	return ret;
}

int checkVertexValid(LinkedGraph* pGraph, int vertexID) {
	int ret = SUCCESS;

	if (vertexID >= pGraph->maxVertexCount
		|| pGraph->pVertex[vertexID] == NOT_USED) {
		printf("오류,노드 ID[%d]\n", vertexID);
		ret = FAIL;
	}

	return ret;
}

int removeVertexLG(LinkedGraph* pGraph, int vertexID)
{
	int ret = SUCCESS;
	int i = 0;

	if (pGraph != NULL) {
		if (checkVertexValid(pGraph, vertexID) != SUCCESS) {
			ret = FAIL;
			return ret;
		}
		for(i = 0; i < pGraph->maxVertexCount; i++) {
			removeEdgeLG(pGraph, vertexID, i);
			removeEdgeLG(pGraph, i, vertexID);
		}
		pGraph->pVertex[vertexID] = NOT_USED;
	}

	return ret;
}

// 간선 제거
int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	int ret = SUCCESS;

	if (pGraph != NULL)
	{
		if (checkVertexValid(pGraph, fromVertexID) != SUCCESS) {
			ret = FAIL;
			return ret;
		}
		if (checkVertexValid(pGraph, toVertexID) != SUCCESS) {
			ret = FAIL;
			return ret;
		}

		deleteGraphNode(pGraph->ppAdjEdge[fromVertexID], toVertexID);

		// 무방향 그래프의 대칭성(Symmetry) 처리.
		// 방향 그래프라면 필요없음.
		if (pGraph->graphType == GRAPH_UNDIRECTED) {
			deleteGraphNode(pGraph->ppAdjEdge[toVertexID], fromVertexID);
		}
	}

	return ret;
}

void deleteGraphNode(LinkedList* pList, int delVertexID)
{
	int i = 0, position = 0;
	ListNode* pNode = NULL;

	position = findGraphNodePosition(pList, delVertexID);
	if (position >= 0) {
		removeLLElement(pList, position);
	}
}

int findGraphNodePosition(LinkedList* pList, int vertexID)
{
	int i = 0, position = 0;
	ListNode* pNode = NULL;

	if (pList != NULL) {
		pNode = pList->headerNode.pLink;
		while(pNode != NULL) {
			if (pNode->data.vertexID == vertexID) {
				return position;
			}

			pNode = pNode->pLink;
			position++;
		}
	}

	return -1;
}


int getEdgeCountLG(LinkedGraph* pGraph) {
	int ret = 0;
	
	if (pGraph != NULL) {
		ret = pGraph->currentEdgeCount;
	}

	return ret;
}

int getVertexCountLG(LinkedGraph* pGraph) {
	int ret = 0;

	if (pGraph != NULL) {
		ret = pGraph->currentVertexCount;
	}

	return ret;
}

int getMaxVertexCountLG(LinkedGraph* pGraph)
{
	int ret = 0;

	if (pGraph != NULL) {
		ret = pGraph->maxVertexCount;
	}

	return ret;
}

int getGraphTypeLG(LinkedGraph* pGraph)
{
		int ret = 0;

	if (pGraph != NULL) {
		ret = pGraph->graphType;
	}

	return ret;
}

void displayLinkedGraph(LinkedGraph* pGraph)
{
	int i = 0;
	int j = 0;
	int position = 0;
	ListNode* pNode = NULL;

	if (pGraph != NULL) {
		for(i = 0; i < pGraph->maxVertexCount; i++)	{
			for(j = 0; j < pGraph->maxVertexCount; j++) {
				position = findGraphNodePosition(pGraph->ppAdjEdge[i], j);

				if (position >=0) {
					pNode = getLLElement(pGraph->ppAdjEdge[i], position);
					printf("%d ", pNode->data.weight);
				}
				else {
					printf("0 ");
				}
			}
			printf("\n");
		}
	}
}

void deleteLinkedGraph(LinkedGraph* pGraph)
{
	int i = 0;

	if (pGraph != NULL) {
		for(i = 0; i < pGraph->maxVertexCount; i++) {
			deleteLinkedList(pGraph->ppAdjEdge[i]);
		}
		if (pGraph->ppAdjEdge != NULL) free(pGraph->ppAdjEdge);
		if (pGraph->pVertex != NULL) free(pGraph->pVertex);
		free(pGraph);
	}
}

int isEmptyLG(LinkedGraph* pGraph)
{
	int ret = TRUE;

	if (pGraph != NULL) {
		if (pGraph->currentVertexCount > 0) {
			ret = FALSE;
		}
	}

	return ret;
}
