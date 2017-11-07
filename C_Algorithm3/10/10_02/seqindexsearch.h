#ifndef _SEQUENTIAL_INDEX_SEARCH_
#define _SEQUENTIAL_INDEX_SEARCH_

typedef struct IndexTableType {
	int position;
	int key;
} IndexTable;

// 색인 순차 검색.
int sequentialIndexSearch(int value[], int size, 
				   IndexTable index[], int indexSize, int key);

// 순차 검색 (오름차순 정렬된 배열, 자료 집합 대상).
int sequentialRangeSearchAsendingSorted(int value[], int start, int end, int key);

// 색인 테이블 생성.
IndexTable* createIndexTable(int value[], int size, int indexSize);

// 색인 테이블 내용을 출력.
void showIndexTable(IndexTable* pIndexTable, int indexSize);

#endif

#ifndef _COMMON_SEARCH_DEF_
#define _COMMON_SEARCH_DEF_

#define TRUE		1
#define FALSE		0
#define FAIL		-1
#endif