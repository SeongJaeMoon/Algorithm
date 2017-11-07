#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqsearch.h"

// 순차 검색 (정렬되지 않은 배열).
int sequentialSearchNotSorted(int value[], int size, int key)
{
	int ret = FAIL;
	int i = 0;

	for(i = 0; i < size && value[i] != key; i++) {
		// do nothing.
	}

	if (i < size) {
		ret = i;
	}

	return ret;
}

// 순차 검색 (오름차순 정렬된 배열).
int sequentialSearchAsendingSorted(int value[], int size, int key)
{
	int ret = FAIL;

	int i = 0;
	for(i = 0; i < size && value[i] < key; i++) {
		// do nothing.
	}

	if (i < size && value[i] == key) {
		ret = i;
	}

	return ret;
}

// 배열의 내용을 출력.
void showArray(int value[], int size)
{
	int i = 0;

	printf("position,key\n");
	printf("------------\n");
	for(i = 0; i < size; i++) {
		printf("%d,%d\n", i, value[i]);
	}
}
