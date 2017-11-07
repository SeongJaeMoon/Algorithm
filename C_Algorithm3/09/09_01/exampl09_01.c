#include <stdio.h>
#include <stdlib.h>

void printArray(int value[], int count);

void slectionSort(int value[], int count)
{
	int i = 0, j = 0;
	int min = 0, temp = 0;

	for(i = 0; i < count-1; i++) {
		min = i;
		for(j = i+1; j < count; j++) {
			if (value[j] < value[min]) {
				min  = j;
			}
		}
		temp = value[i];
		value[i] = value[min];
		value[min] = temp;

		printf("Step-%d,", i+1);
		printArray(value, count);
	}
}

int main(int argc, char *argv[])
{
	int values[] = {80, 50, 70, 10, 60, 20, 40, 30 };


	printf("Before Sort\n");
	printArray(values, 8);

	slectionSort(values, 8);

	printf("\nAfter Sort\n");
	printArray(values, 8);

	return 0;
}

void printArray(int value[], int count)
{
	int i = 0;
	for(i = 0; i < count; i++) {
		printf("%d ", value[i]);
	}
	printf("\n");
}
