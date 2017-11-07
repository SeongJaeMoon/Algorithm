#ifndef _ARRAY_HEAP_
#define _ARRAY_HEAP_

typedef struct HeapElementType
{
	int key;
	char element;
} HeapNode;

typedef struct ArrayHeapType
{
	int maxElementCount;		// 최대 노드 개수
	int currentElementCount;	// 현재 노드 개수
	HeapNode *pElement;		// 노드 저장을 위한 1차원 array
} ArrayMaxHeap, ArrayMinHeap;

// 최대 히프의 생성
ArrayMaxHeap* createArrayMaxHeap(int maxElementCount);

// 최대 히프의 삭제
void deleteArrayMaxHeap(ArrayMaxHeap* pArrayHeap);

// 최소 히프의 생성
ArrayMinHeap* createArrayMinHeap(int maxElementCount);

// 최소 히프의 삭제
void deleteArrayMinHeap(ArrayMinHeap* pArrayHeap);

// 최대 히프의 삽입
void insertMaxHeapAH(ArrayMaxHeap* pArrayHeap, HeapNode element);

// 최대 히프의 삭제
HeapNode* deleteMaxHeapAH(ArrayMaxHeap* pArrayHeap);

// 최소 히프의 삽입
void insertMinHeapAH(ArrayMinHeap* pArrayHeap, HeapNode element);

// 최소 히프의 삭제
HeapNode* deleteMinHeapAH(ArrayMinHeap* pArrayHeap);

// 히프 정보 출력
void displayArrayHeap(ArrayMaxHeap* pList);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif