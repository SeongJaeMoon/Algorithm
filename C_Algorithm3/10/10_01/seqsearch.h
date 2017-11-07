#ifndef _SEQUENTIAL_SEARCH_
#define _SEQUENTIAL_SEARCH_

// 순차 검색 (정렬되지 않은 배열).
int sequentialSearchNotSorted(int value[], int size, int key);

// 순차 검색 (오름차순 정렬된 배열).
int sequentialSearchAsendingSorted(int value[], int size, int key);

// 배열의 내용을 출력.
void showArray(int value[], int size);

#endif

#ifndef _COMMON_SEARCH_DEF_
#define _COMMON_SEARCH_DEF_

#define TRUE		1
#define FALSE		0
#define FAIL		-1
#endif