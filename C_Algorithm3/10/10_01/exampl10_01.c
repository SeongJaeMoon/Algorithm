#include <stdio.h>
#include <stdlib.h>
#include "seqsearch.h"

int main(int argc, char *argv[])
{
	int index = 0;
	int key = 0;
	int notSortedArray[] = {80, 50, 70, 10, 60, 20};
	int ascSortedArray[] = {10, 20, 50, 60, 70, 80};

	// 1. 정렬되어 있지 않은 경우.
	showArray(notSortedArray, 6);

	// 1-1.검색 성공의 경우: 키 값 70.
	key = 70;
	index = sequentialSearchNotSorted(notSortedArray, 6, key);
	if (index >= 0) {
		printf("키-%d,위치-%d\n", key, index);
	}
	else {
		printf("키-%d,검색 실패\n", key);
	}

	// 1-2.검색 실패의 경우: 키 값 25.
	key = 25;
	index = sequentialSearchNotSorted(notSortedArray, 6, key);
	if (index >= 0) {
		printf("키-%d,위치-%d\n", key, index);
	}
	else {
		printf("키-%d,검색 실패\n", key);
	}

	// 2. 정렬되어 있는 경우.
	showArray(ascSortedArray, 6);

	// 2-1.검색 성공의 경우: 키 값 70.
	key = 70;
	index = sequentialSearchAsendingSorted(ascSortedArray, 6, key);
	if (index >= 0) {
		printf("키-%d,위치-%d\n", key, index);
	}
	else {
		printf("키-%d,검색 실패\n", key);
	}

	// 2-2.검색 실패의 경우: 키 값 25.
	key = 25;
	index = sequentialSearchAsendingSorted(ascSortedArray, 6, key);
	if (index >= 0) {
		printf("키-%d,위치-%d\n", key, index);
	}
	else {
		printf("키-%d,검색 실패\n", key);
	}

	return 0;
}
