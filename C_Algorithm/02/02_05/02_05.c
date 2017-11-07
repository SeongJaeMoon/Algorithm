#include <stdio.h>
#include <string.h>

void main(int arc, char **argv) {
	int size = 0;
	
	int	int_value = 100;
	int	*ptr_int = NULL;
	int	**pptr_int = NULL;

	float	float_value = 5.23f;
	float	*ptr_float = & float_value;

	char char_value_A = 'A';
	char char_value_B = 'B';
	char *ptr_char = NULL;

	ptr_int = &int_value;
	printf("변수 int_value의 값: %d\n", int_value);
	printf("포인터 변수 ptr_int의 값: %x\n", ptr_int);
	printf("포인터 변수 ptr_int가 가리키는 주소의 값: %d\n", *ptr_int);

	printf("변수 float_value의 값: %f\n", float_value);
	printf("포인터 변수 ptr_float의 값: %x\n", ptr_float);
	printf("포인터 변수 ptr_float가 가리키는 주소의 값: %f\n", *ptr_float);

	ptr_char = &char_value_A;
	printf("변수 char_value_A의 값: %c\n", char_value_A);
	printf("변수 char_value_B의 값: %c\n", char_value_B);
	printf("포인터 변수 ptr_char의 값: %x\n", ptr_char);
	printf("포인터 변수 ptr_char가 가리키는 주소의 값: %c\n", *ptr_char);

	*ptr_char = char_value_B;
	printf("변수 char_value_A의 값: %c\n", char_value_A);
	printf("변수 char_value_B의 값: %c\n", char_value_B);
	printf("포인터 변수 ptr_char의 값: %x\n", ptr_char);
	printf("포인터 변수 ptr_char가 가리키는 주소의 값: %c\n", *ptr_char);

	char_value_A = 'A';
	char_value_B = 'B';
	ptr_char = &char_value_A;
	char_value_B = *ptr_char;
	printf("변수 char_value_A의 값: %c\n", char_value_A);
	printf("변수 char_value_B의 값: %c\n", char_value_B);
	printf("포인터 변수 ptr_char의 값: %x\n", ptr_char);
	printf("포인터 변수 ptr_char가 가리키는 주소의 값: %c\n", *ptr_char);

	pptr_int = &ptr_int;
	printf("변수 int_value의 값: %d\n", int_value);
	printf("포인터 변수 ptr_int의 값: %x\n", ptr_int);
	printf("포인터 변수 ptr_int가 가리키는 주소의 값: %d\n", *ptr_int);
	printf("더블 포인터 변수 pptr_int의 값: %x\n", pptr_int);
	printf("더블 포인터 변수 pptr_int가 가리키는 주소의 값: %x\n", *pptr_int);
	printf("더블 포인터 변수 pptr_int가 가리키는 주소가 가리키는 값: %d\n", **pptr_int);
}
