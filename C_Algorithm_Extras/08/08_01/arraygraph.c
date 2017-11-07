#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraygraph.h"

ArrayGraph* createArrayGraph(int maxVertexCount)
{
	int i = 0, j = 0;
	ArrayGraph *pReturn = NULL;

	if (maxVertexCount > 0)	{
		pReturn = (ArrayGraph *)malloc(sizeof(ArrayGraph));
		if (pReturn == NULL) {
			printf("오류, 메모리할당(1), in createArrayGraph()\n");
			return NULL;
		}
		pReturn->graphType = GRAPH_UNDIRECTED;
		pReturn->maxVertexCount = maxVertexCount;
	}
	else {
		printf("오류, 최대 노드 개수는 0보다 커야합니다\n");
		return NULL;
	}

	pReturn->pVertex = (int *)malloc(sizeof(int) * maxVertexCount);
	if (pReturn->pVertex == NULL) {
		printf("오류, 메모리할당(2), in createArrayGraph()\n");
		if (pReturn != NULL) free(pReturn);
		return NULL;
	}

	pReturn->ppAdjEdge = (int **)malloc(sizeof(int *) * maxVertexCount);
	if (pReturn->ppAdjEdge == NULL) {
		printf("오류, 메모리할당(3), in createArrayGraph()\n");
		if (pReturn->pVertex != NULL) free(pReturn->pVertex);
		if (pReturn != NULL) free(pReturn);
		return NULL;
	}

	for(i = 0; i < maxVertexCount; i++) {
		pReturn->ppAdjEdge[i] = (int *)malloc(sizeof(int) * maxVertexCount);
		if (pReturn->ppAdjEdge[i] == NULL) {
			printf("오류, 메모리할당(4), in createArrayGraph()\n");
			for(j = 0; j < i-1; j++) {
				if (pReturn->ppAdjEdge[j] != NULL) free(pReturn->ppAdjEdge[j]);
			}
			if (pReturn->ppAdjEdge != NULL) free(pReturn->ppAdjEdge);
			if (pReturn->pVertex != NULL) free(pReturn->pVertex);
			if (pReturn != NULL) free(pReturn);
			return NULL;
		}
	}

	memset(pReturn->pVertex, NOT_USED, sizeof(int) * maxVertexCount);
	for(i = 0; i < maxVertexCount; i++) {
		memset(pReturn->ppAdjEdge[i], 0, sizeof(int) * maxVertexCount);
	}

	return pReturn;
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph* pReturn = NULL;

	pReturn = createArrayGraph(maxVertexCount);
	if (pReturn != NULL) {
		pReturn->graphType = GRAPH_DIRECTED;
	}

	return pReturn;
}

int addVertexAG(ArrayGraph* pGraph, int vertexID)
{
	int ret = SUCCESS;

	if (pGraph != NULL) {
		if (vertexID < pGraph->maxVertexCount) {
			if (pGraph->pVertex[vertexID] == NOT_USED) {
				pGraph->pVertex[vertexID] = USED;
				pGraph->currentVertexCount++;
			}
			else {
				printf("오류, 이미 존재하는 노드[%d],in addVertexAG()\n", 
						vertexID);
				ret = FAIL;
			}
		}
		else {
			printf("오류, 최대 노드 개수 초과 [%d], in addVertexAG()\n",
					pGraph->maxVertexCount);
			ret = FAIL;
		}
	}

	return ret;
}

int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
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
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;

		if (pGraph->graphType == GRAPH_UNDIRECTED) {
			pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
		}
	}

	return ret;
}

int checkVertexValid(ArrayGraph* pGraph, int vertexID) {
	int ret = SUCCESS;

	if (vertexID >= pGraph->maxVertexCount
		|| pGraph->pVertex[vertexID] == NOT_USED) {
		printf("오류, 노드 정보[%d]\n", 
				vertexID);
		ret = FAIL;
	}

	return ret;
}

int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	return addEdgewithWeightAG(pGraph, fromVertexID, toVertexID, USED);
}

int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
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

		pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;

		if (pGraph->graphType == GRAPH_UNDIRECTED) {
			pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
		}
	}

	return ret;
}

int removeVertexAG(ArrayGraph* pGraph, int vertexID)
{
	int ret = SUCCESS;
	int i = 0;

	if (pGraph != NULL) {
		if (checkVertexValid(pGraph, vertexID) != SUCCESS) {
			ret = FAIL;
			return ret;
		}
		for(i = 0; i < pGraph->maxVertexCount; i++) {
			removeEdgeAG(pGraph, vertexID, i);
			removeEdgeAG(pGraph, i, vertexID);
		}
		pGraph->pVertex[vertexID] = NOT_USED;
	}

	return ret;
}

void displayArrayGraph(ArrayGraph* pGraph)
{
	int i = 0;
	int j = 0;

	if (pGraph != NULL) {
		for(i = 0; i < pGraph->maxVertexCount; i++)	{
			for(j = 0; j < pGraph->maxVertexCount; j++) {
				printf("%d ", pGraph->ppAdjEdge[i][j]);
			}
			printf("\n");
		}
	}
}

void deleteArrayGraph(ArrayGraph* pGraph)
{
	int i = 0;

	if (pGraph != NULL) {
		for(i = 0; i < pGraph->maxVertexCount; i++) {
			free(pGraph->ppAdjEdge[i]);
		}
		free(pGraph->ppAdjEdge);
		free(pGraph->pVertex);
		free(pGraph);
	}
}

int isEmptyAG(ArrayGraph* pGraph)
{
	int ret = TRUE;

	if (pGraph != NULL) {
		if (pGraph->currentVertexCount > 0) {
			ret = FALSE;
		}
	}

	return ret;
}
