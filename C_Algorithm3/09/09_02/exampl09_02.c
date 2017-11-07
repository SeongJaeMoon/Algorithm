#include <stdio.h>
#include <stdlib.h>

void printArray(int value[], int count);

// 버블 정렬.
void bubbleSort(int value[], int count)
{
	int i = 0, j = 0;
	int temp = 0;

	for(i = count - 1; i >= 0; i--) {
		for(j = 0; j <= i; j++) {
			if (value[j-1] > value[j]) {
				temp = value[j-1];
				value[j-1] = value[j];
				value[j] = temp;
			}
		}

		printf("Step-%d,", count - i);
		printArray(value, count);
	}
}

int main(int argc, char *argv[])
{
	int values[] = {80, 50, 70, 10, 60, 20, 40, 30 };

	printf("Before Sort\n");
	printArray(values, 8);

	bubbleSort(values, 8);

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
