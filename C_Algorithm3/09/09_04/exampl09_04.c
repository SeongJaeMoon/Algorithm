#include <stdio.h>
#include <stdlib.h>

void printArray(int value[], int count);

// 삽입 정렬.
void insertionSort(int value[], int count)
{
	int i = 0, j = 0;
	int temp = 0;

	for(i = 1; i < count; i++) {
		temp = value[i];
		j = i;
		while((j > 0) && value[j-1] > temp) {
			value[j] = value[j-1];
			j = j - 1;
		}
		value[j] = temp;

		printf("Step-%d,", i);
		printArray(value, count);
	}
}

int main(int argc, char *argv[])
{
	int values[] = {80, 50, 70, 10, 60, 20, 40, 30 };
	int *pBuffer = NULL;

	printf("Before Sort\n");
	printArray(values, 8);

	insertionSort(values, 8);

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
