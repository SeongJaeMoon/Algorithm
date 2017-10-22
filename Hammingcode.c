#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_BIT_LENGTH 6

typedef unsigned int UINT;

UINT ConvertHammingCode(const UINT p_data);	// code_bit_length 반환.
UINT CorrectHammingCode(const UINT p_code);
UINT GetHammingCodeLength(const UINT p_data);

UINT ReverseRandomOneBit(const UINT p_bit_length, const UINT p_code);	// srand 호출해야 됨.

void PrintI2B(const UINT p_print_bit_length, const UINT p_data);	// Print UINT to Binary, 이진 데이터 출력용


int main(void)
{
	int original_code, hamming_code, one_bit_error_code, correction_code;
	UINT hamming_code_length;

	srand((UINT)time(NULL));

	original_code = 30;
	printf("원본 데이터 : "); PrintI2B(DATA_BIT_LENGTH, original_code); puts("");

	hamming_code = ConvertHammingCode(original_code);
	hamming_code_length = GetHammingCodeLength(DATA_BIT_LENGTH);
	printf("해밍 코드 : "); PrintI2B(hamming_code_length, hamming_code); puts("");

	one_bit_error_code = ReverseRandomOneBit(hamming_code_length, hamming_code);
	printf("1bit 오류 코드 : "); PrintI2B(hamming_code_length, one_bit_error_code); puts("");

	correction_code = CorrectHammingCode(one_bit_error_code);
	printf("오류 정정 코드 : "); PrintI2B(hamming_code_length, correction_code); puts("");

	return 0;
}

UINT ConvertHammingCode(const UINT p_data)
{
	UINT i, mask;
	UINT hamming_code, code_bit_length;
	UINT parity_bit_length, parity_position, parity_set;
	UINT data_bit_length;

	/* Get Length */
	for (i = 1, mask = 0x01; mask != 0; mask <<= 1, i++)
		if (mask & p_data) data_bit_length = i;
	code_bit_length = GetHammingCodeLength(data_bit_length);

	/* HammingCode Path One (패리티비트 전부 0으로 하고 생성) */
	hamming_code = 0, parity_position = 0x01, mask = 0x01;
	for (i = 1; i <= code_bit_length; i++)	// i번째 비트에 관해, 번호는 ...54321 순이다.
	{
		if (i == parity_position)
			parity_position <<= 1;	// 1, 2, 4, 8, ...
		else{
			if (mask & p_data)
				hamming_code |= (0x01 << (i - 1));
			mask <<= 1;
		}
	}

	/* Calculation ParitySet */
	parity_set = 0, mask = 0x01;
	for (i = 1; i <= code_bit_length; i++, mask<<=1)
		if (mask & hamming_code) parity_set ^= i;			// P4P3P2P1이 1010이라면, parity_set == 10

	/* HammingCode Path Two (패리티비트 완성) */
	parity_bit_length = code_bit_length - data_bit_length;
	for (mask = 0x01, i = 1; i <= parity_bit_length; i++, mask <<= 1)
		if (mask & parity_set) hamming_code |= (0x01 << (mask - 1));

	return hamming_code;
}
UINT CorrectHammingCode(const UINT p_code)
{
	UINT i = 1, mask = 0x01;
	UINT syndrom = 0;

	while (mask){
		if (mask & p_code) syndrom ^= i;
		mask <<= 1, i++;
	}
	return (syndrom) ? p_code ^ (0x01 << (syndrom - 1)) : p_code;
}
UINT GetHammingCodeLength(const UINT p_data_bit_length)
{
	UINT parity_bit_length = 2;
	UINT i = 0x01 << parity_bit_length; // i = pow(2, parity_count);

	while (!(i >= p_data_bit_length + parity_bit_length + 1))
		parity_bit_length++, i <<= 1;

	return (p_data_bit_length + parity_bit_length);
}

UINT ReverseRandomOneBit(const UINT p_bit_length, const UINT p_code)
{
	return p_code ^ (0x01 << (rand() % p_bit_length));
}

void PrintI2B(const UINT p_print_bit_length, const UINT p_data)
{
	UINT mask = 0x01 << p_print_bit_length;
	while (mask >>= 1)
		putc((mask&p_data) ? '1' : '0', stdout);
}
