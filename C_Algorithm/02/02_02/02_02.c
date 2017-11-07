#include <stdio.h>
#include <string.h>

void main(int arc, char **argv) {
	int i = 0, size = 0;
	int key1[3] = {3,5,7};
	int key2[3] = {0,};
	char string1[] = "value";
	char string2[100] = {0,};

	key2[0] = 3;
	key2[1] = 5;
	key2[2] = 7;

	size = sizeof(key1) / sizeof(int);
	printf("key1의 원소 개수: %d\n", size);
	for(i = 0; i < size; i++) {
		printf("%d->%d\n", i, key1[i]);
	}

	size = sizeof(key1) / sizeof(int);
	printf("key2의 원소 개수: %d\n", size);
	for(i = 0; i < size; i++) {
		printf("%d->%d\n", i, key2[i]);
	}

	size = sizeof(string1) / sizeof(char);
	printf("string1의 원소 개수: %d\n", size);
	printf("string1: %s\n", string1);

	strcpy(string2, "strcpy로 복사하기");
	size = sizeof(string2) / sizeof(char);
	printf("string2의 원소 개수: %d\n", size);
	printf("string2: %s\n", string2);
}
