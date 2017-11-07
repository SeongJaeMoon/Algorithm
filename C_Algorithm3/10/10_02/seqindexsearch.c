#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqindexsearch.h"

// 색인 순차 검색.
int sequentialIndexSearch(int value[], int size, 
			   IndexTable index[], int indexSize, int key)
{
	int ret = FAIL;
	int i = 0;
	int start = 0, end = 0;

	if (key >= value[0] && key <= value[size-1]) {
		for(i = 0; i < indexSize; i++) {
			if (index[i].key > key) {
				break;
			}
		}
		if (i >= indexSize) {
			start = index[i-1].position;
			end = size - 1;
		}
		else {
			start = index[i-1].position;
			end = index[i].position - 1;
		}

		ret = sequentialRangeSearchAsendingSorted(value, start, end, key);
	}

	return ret;
}

// 순차 검색 (오름차순 정렬된 배열, 자료 집합 대상).
int sequentialRangeSearchAsendingSorted(int value[], int start, int end, int key)
{
	int ret = FAIL;
	int i = 0;
	for(i = start; i <= end && value[i] < key; i++) {
		// do nothing.
	}

	if (i <= end && value[i] == key) {
		ret = i;
	}

	return ret;
}

// 색인 테이블 생성.
IndexTable* createIndexTable(int value[], int size, int indexSize)
{
	IndexTable* pReturn = NULL;
	int i = 0;
	int ratio = 0;

	if (size <= 0 || indexSize <= 0) {
		printf("인덱스 크기 및 배열의 크기는 0보다 커야합니다\n");
		return NULL;
	}

	ratio = size / indexSize;
	if (size % indexSize > 0) {
		ratio = ratio + 1;
	}

	pReturn = (IndexTable*) malloc(sizeof(IndexTable) * indexSize);
	if (pReturn == NULL) {
		printf("오류, 메모리할당 in createIndexTable()\n");
		return NULL;
	}

	for(i = 0; i < indexSize; i++) {
		pReturn[i].position = i * ratio;
		pReturn[i].key = value[ i * ratio ];
	}

	return pReturn;
}

// 색인 테이블 내용을 출력.
void showIndexTable(IndexTable* pIndexTable, int indexSize)
{
	int i = 0;

	printf("인덱스 테이블\n");
	printf("위치,키\n");
	printf("------------\n");
	for(i = 0; i < indexSize; i++) {
		printf("%d,%d\n", pIndexTable[i].position, pIndexTable[i].key);
	}
}