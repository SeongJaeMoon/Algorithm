#include <stdio.h>
#include <stdlib.h>

int partitionQuickSort(int value[], int start, int end);
void printArray(int value[], int count);

// 퀵 정렬.
void quickSort(int value[], int start, int end)
{
	int pivot = 0;
	if (start < end) {
		pivot = partitionQuickSort(value, start, end);
		quickSort(value, start, pivot - 1);
		quickSort(value, pivot+1, end);
	}
}

int partitionQuickSort(int value[], int start, int end)
{
	int pivot = 0;
	int temp = 0, left = 0, right = 0;
	left = start;
	right = end;
	pivot = end;

	while(left < right) {
		while((value[left] < value[pivot]) && (left < right)) {
			left++;
		}
		while((value[right] >= value[pivot]) && (left < right)) {
			right--;
		}

		if (left < right) {
			temp = value[left];
			value[left] = value[right];
			value[right] = temp;

			printf("start-[%d],end-[%d],pivot-[%d],in-loop,", start, end, value[pivot]);
			printArray(value, end - start + 1);
		}
	}
	temp = value[pivot];
	value[pivot] = value[right];
	value[right] = temp;

	printf("start-[%d],end-[%d],pivot-[%d],out-loop,", start, end, value[right]);
	printArray(value, end - start + 1);

	return right;
}

int main(int argc, char *argv[])
{
	int values[] = {80, 50, 70, 10, 60, 20, 40, 30 };

	printf("Before Sort\n");
	printArray(values, 8);

	quickSort(values, 0, 7);

	printf("\nAfter Sort\n");
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
