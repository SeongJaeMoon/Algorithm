#ifndef _GRAPH_MST_KRUSKAL_
#define _GRAPH_MST_KRUSKAL_

// Kruskal 알고리즘
LinkedGraph *mstKruskal(LinkedGraph* pGraph);

// 기존 그래프G의 간선을 가중치 값의 오름차순으로 정렬.
ArrayMinHeap *orderEdges(LinkedGraph* pGraph);

// 순환 검사.
int checkCycle(LinkedGraph* pGraph, int fromVertexID, int toVertexID);

#endif
