#include <stdio.h>
#include <stdlib.h>
#include "seqsearch.h"
#include "binsearch.h"

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

int main(int argc, char *argv[])
{
	int key = 0;
	int index = 0;
	int ascSortedArray[] = {10, 20, 50, 60, 70, 80};
	int arraySize = 6;

	showArray(ascSortedArray, arraySize);

	key = 60;
	index = binarySearchRecursive(ascSortedArray, 0, arraySize, key);
	if (index >= 0) {
		printf("키-%d,위치-%d\n", key, index);
	}
	else {
		printf("키-%d,검색 실패\n", key);
	}

	key = 65;
	index = binarySearchRecursive(ascSortedArray, 0, arraySize, key);
	if (index >= 0) {
		printf("키-%d,위치-%d\n", key, index);
	}
	else {
		printf("키-%d,검색 실패\n", key);
	}

	key = 60;
	index = binarySearch(ascSortedArray, 0, arraySize, key);
	if (index >= 0) {
		printf("키-%d,위치-%d\n", key, index);
	}
	else {
		printf("키-%d,검색 실패\n", key);
	}

	key = 65;
	index = binarySearch(ascSortedArray, 0, arraySize, key);
	if (index >= 0) {
		printf("키-%d,위치-%d\n", key, index);
	}
	else {
		printf("키-%d,검색 실패\n", key);
	}

	
	return 0;
}
