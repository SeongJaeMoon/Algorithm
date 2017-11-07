#include <stdio.h>
#include <stdlib.h>
#include "linkedqueue.h"

void printArray(int value[], int count);

void radixSort(int value[], int count, int radix, int digit) {
	int i = 0, bucket = 0, d = 0, factor = 1;
	LinkedQueue **ppQueue = NULL;
	QueueNode node = {0,};
	ppQueue = (LinkedQueue **)malloc(sizeof(LinkedQueue *) * radix);
	if (ppQueue == NULL) {
		printf("오류, 메모리 할당,radixSort()\n");
		return;
	}
	for(bucket = 0; bucket < radix; bucket++) {
		ppQueue[bucket] = createLinkedQueue();
		if (ppQueue[bucket] == NULL) {
			for(i=0; i < bucket-1; i++) {
				if (ppQueue[i] != NULL) deleteLinkedQueue(ppQueue[i]);
			}
			free(ppQueue);
			printf("오류, createLinkedQueue() in radixSort()\n");
			return;
		}
	}
	for(d = 0; d < digit; d++) {
		for(i = 0; i < count; i++) {
			node.data = value[i];
			enqueueLQ(ppQueue[(value[i]/factor)%radix], node); 
		}
		
		i = 0;
		for(bucket = 0; bucket < radix; bucket++) {
			while(isLinkedQueueEmpty(ppQueue[bucket]) == FALSE) {
				QueueNode *pNode = dequeueLQ(ppQueue[bucket]);
				if (pNode != NULL) {
					value[i] = pNode->data;
					i++;

					free(pNode);
				}
			}
		}

		printf("Digit-%d,", factor);
		printArray(value, count);

		factor = factor * radix;
	}

	for(bucket = 0; bucket < radix; bucket++) {
		deleteLinkedQueue(ppQueue[bucket]);
	}
	free(ppQueue);

}

int main(int argc, char *argv[])
{
	int values[] = {42, 60, 75, 81, 10, 23, 12, 18 };

	printf("Before Sort\n");
	printArray(values, 8);

	radixSort(values, 8, 10, 2);

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
