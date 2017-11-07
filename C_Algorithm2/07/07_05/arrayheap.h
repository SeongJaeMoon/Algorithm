#ifndef _ARRAY_HEAP_
#define _ARRAY_HEAP_

typedef struct HeapElementType
{
	int key;
	char data;
} HeapNode;

typedef struct ArrayHeapType
{
	int maxElementCount;		// 최대 노드 개수
	int currentElementCount;	// 현재 노드 개수
	HeapNode *pElement;		// 노드 저장을 위한 1차원 array
} ArrayMaxHeap, ArrayMinHeap;

ArrayMaxHeap* createArrayMaxHeap(int maxElementCount);
void deleteArrayMaxHeap(ArrayMaxHeap* pArrayHeap);
void insertMaxHeapAH(ArrayMaxHeap* pArrayHeap, HeapNode element);
HeapNode* deleteMaxHeapAH(ArrayMaxHeap* pArrayHeap);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif