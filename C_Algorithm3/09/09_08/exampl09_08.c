#include <stdio.h>
#include <stdlib.h>
#include "arrayheap.h"

void printArray(int value[], int count);

// 힙 정렬.
void heapSort(int value[], int count)
{
	int i = 0;
	ArrayMinHeap* pHeap = NULL;

	pHeap = createArrayMinHeap(8);
	if (pHeap != NULL) {
		HeapNode node;

		for(i = 0; i < count; i++) {
			node.key = value[i];
			insertMinHeapAH(pHeap, node);
		}

		for(i = 0; i < count; i++) {
			HeapNode *pNode = deleteMinHeapAH(pHeap);
			if (pNode != NULL) {
				value[i] = pNode->key;

				free(pNode);
			}
		}

		deleteArrayMinHeap(pHeap);
	}
	else {
		printf("오류, createArrayMinHeap() in heapSort()\n");
		return;
	}
}

int main(int argc, char *argv[])
{
	int values[] = {10, 50, 70, 80, 60, 20, 40, 30 };

	printf("Before Sort\n");
	printArray(values, 8);

	heapSort(values, 8);

	printf("After Sort\n");
	printArray(values, 8);

	return 0;
}

// 배열 내용 출력
void printArray(int value[], int count)
{
	int i = 0;
	for(i = 0; i < count; i++) {
		printf("%d ", value[i]);
	}
	printf("\n");
}

