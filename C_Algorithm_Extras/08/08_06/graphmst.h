#ifndef _GRAPH_MST_
#define _GRAPH_MST_

typedef struct GraphEdgeType
{
	int vertexIDFrom;		// Tail 노드 ID
	int vertexIDTo;			// Head 노드 ID
	int	weight;				// 가중치
} GraphEdge;

// 순환 검사.
int checkCycle(LinkedGraph* pGraph, int fromVertexID, int toVertexID);

// Prim 알고리즘
LinkedGraph *mstPrim(LinkedGraph* pGraph, int vertexID);

// 정점(mstVertexID)과 부속된 모든 간선들 중, 
// 가중치가 가장 작으면서 순환을 발생시키지 않는 간선을 선택.
void getMinWeightEdge(LinkedGraph* pGraph, LinkedGraph* pMST,
					  int mstVertexID, GraphEdge *pMinWeightEdge);

int checkEdge(LinkedGraph* pGraph, int fromVertexID, int toVertexID);

#define		MAX_INT		99999
#endif
