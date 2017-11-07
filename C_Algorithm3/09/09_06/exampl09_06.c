#include <stdio.h>
#include <stdlib.h>

void printArray(int value[], int count);
void mergSortInternal(int value[], int buffer[], int start, int middle, int end);

// 병합 정렬.
void mergeSort(int value[], int buffer[], int start, int end)
{
	int middle = 0;
	if (start < end) {
		middle = (start + end) / 2;
		mergeSort(value, buffer, start, middle);
		mergeSort(value, buffer, middle+1, end);
		mergSortInternal(value, buffer, start, middle, end);
	}
}

void mergSortInternal(int value[], int buffer[], int start, int middle, int end)
{
	int i = 0, j = 0, k = 0, t = 0;
	i = start;
	j = middle + 1;
	k = start;

	while(i <= middle && j <= end) {
		if (value[i] <= value[j]) {
			buffer[k] = value[i];
			i++;
		}
		else {
			buffer[k] = value[j];
			j++;
		}
		k++;
	}

	if (i > middle) {
		for(t = j; t <= end; t++, k++) {
			buffer[k] = value[t];
		}
	}
	else {
		for(t = i; t <= middle; t++, k++) {
			buffer[k] = value[t];
		}
	}
	for(t = start; t <= end; t++) {
		value[t] = buffer[t];
	}

	printf("start-%d,middle-%d,end-%d,", start, middle, end);
	for(t = start; t <= end; t++) {
		printf("%d ", value[t]);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	int values[] = {80, 50, 70, 10, 60, 20, 40, 30 };
	int *pBuffer = NULL;

	printf("Before Sort\n");
	printArray(values, 8);

	pBuffer = (int *)malloc(sizeof(int) * 8);
	if (pBuffer != NULL) {
		mergeSort(values, pBuffer, 0, 7);

		free(pBuffer);
	}

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

