#include <stdio.h>

void main(int arc, char **argv) {
	int size_char = sizeof(char);
	int size_int = sizeof(int);
	int size_short = sizeof(short);
	int size_long = sizeof(long);
	int size_float = sizeof(float);
	int size_double = sizeof(double);

	printf("char = %d\n", size_char);
	printf("int = %d\n", size_int);
	printf("short = %d\n", size_short);
	printf("long = %d\n", size_long);
	printf("float = %d\n", size_float);
	printf("double = %d\n", size_double);
}
