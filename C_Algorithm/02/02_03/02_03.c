#include <stdio.h>

void main(int arc, char **argv) {
	int i = 0, j = 0, k = 0, size = 0;

	int multi_values1[2][3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
	int multi_values2[2][3][4] = { {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}, 
									{13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24}};
	int multi_values3[2][3][4] = { {
										{1, 2, 3, 4}, 
										{5, 6, 7, 8},
										{9, 10, 11, 12}
									},
									{
										{13, 14, 15, 16}, 
										{17, 18, 19, 20}, 
										{21, 22, 23, 24}
									}};

	int multi_values4[2][3][4] = { 0, };

	multi_values4[0][0][0] = 1;
	multi_values4[0][0][1] = 2;
	multi_values4[0][0][2] = 3;
	multi_values4[0][0][3] = 4;
	multi_values4[0][1][0] = 5;
	multi_values4[0][1][1] = 6;
	multi_values4[0][1][2] = 7;
	multi_values4[0][1][3] = 8;
	multi_values4[0][2][0] = 9;
	multi_values4[0][2][1] = 10;
	multi_values4[0][2][2] = 11;
	multi_values4[0][2][3] = 12;
	multi_values4[1][0][0] = 13;
	multi_values4[1][0][1] = 14;
	multi_values4[1][0][2] = 15;
	multi_values4[1][0][3] = 16;
	multi_values4[1][1][0] = 17;
	multi_values4[1][1][1] = 18;
	multi_values4[1][1][2] = 19;
	multi_values4[1][1][3] = 20;
	multi_values4[1][2][0] = 21;
	multi_values4[1][2][1] = 22;
	multi_values4[1][2][2] = 23;
	multi_values4[1][2][3] = 24;
	
	size = sizeof(multi_values1) / sizeof(int);
	printf("element count of multi_values1: %d\n", size);
	for(i = 0; i < 2; i++) {
		for(j = 0; j < 3; j++) {
			for(k = 0; k < 4; k++) {
				printf("[%d][%d][%d]->%d\t", i, j, k, multi_values1[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}

	size = sizeof(multi_values4) / sizeof(int);
	printf("element count of multi_values4: %d\n", size);
	for(i = 0; i < 2; i++) {
		for(j = 0; j < 3; j++) {
			for(k = 0; k < 4; k++) {
				printf("[%d][%d][%d]->%d\t", i, j, k, multi_values4[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
